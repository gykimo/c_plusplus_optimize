# c_plusplus_optimize
summarize optimize methods for c/c++.  
please watch 'user' and 'sys' cost time.  
how to run: cd one case dir, and excute ./run.sh, then will print cost logs.  

主要总结一些C、C++的优化方法。  
耗时对比主要看user和sys两个耗时对比。  
进入每个示例，直接执行./run.sh，就可以打印出相应的对比log。 

# cases
## pointerset_vs_valueset(1 vs 2)
pointerset is better than valueset, about more than 50% improvement.

```
good: pointerset

real	0m0.428s
user	0m0.220s
sys	0m0.002s

==========================

bad: valueset

real	0m0.711s
user	0m0.499s
sys	0m0.004s
```

## add_vs_macro_vs_inline_func_vs_func_vs_atomic
```
[case 1] add_+:

real	0m0.756s
user	0m0.234s
sys	0m0.003s

==========================
[case 2] add_macro:

real	0m0.314s
user	0m0.234s
sys	0m0.003s

==========================
[case 3] add_inline_func:

real	0m0.680s
user	0m0.378s
sys	0m0.002s

==========================
[case 4] add_func:

real	0m0.791s
user	0m0.388s
sys	0m0.003s

==========================
[case 5] add_atomic:

real	0m1.278s
user	0m0.937s
sys	0m0.004s
```

## shared_ptr_vs_other_auto_ptr
Linux:
```
[case 1] shared_ptr:

real	0m0.515s
user	0m0.511s
sys	0m0.001s

==========================
[case 2] webrtc_ref:

real	0m0.277s
user	0m0.275s
sys	0m0.000s


```

## shared_ptr_vs_not
```
[case 1] not_share_ptr_1attrs:

real	0m0.746s
user	0m0.230s
sys	0m0.005s

==========================
[case 2] not_share_ptr_1000attrs:

real	0m5.798s
user	0m5.362s
sys	0m0.023s

==========================
[case 3] share_ptr:

real	0m5.422s
user	0m5.059s
sys	0m0.018s
```

## mutex_vs_recursive_mutex
```
[case 1] mutex:

real	0m2.942s
user	0m2.321s
sys	0m5.533s

==========================
[case 2] recursive_mutex:

real	0m4.278s
user	0m3.592s
sys	0m9.022s
```

## spinlock_vs_mutex
spinlock(spinlock_webrtc) is better if protected scope consumes little time.  
mutex(mutex_heavy_task) is better if protected scope consumes much time. 

### protected scope consume little time
like cases bellow, count_ plus 1 safely, that will cost little time.  

#### mutex
sys cost much, because mutex need system scheduling  
user cost is near with user cost of spinlock_webrtc  
logs bellow:  

```
[case 1] mutex:

real	0m1.594s
user	0m0.717s
sys	0m0.997s
```

#### spinlock_loop_nothing
doing nothing in each loop is not good, because that causes many __sync_val_compare_and_swap times.  
so user cost is very high, but sys cost is very low.  
this case shows that if spinlock is not implemented well, it's performance will be worse than mutex.  

```
[case 2] spinlock_loop_nothing:

real	0m2.348s
user	0m4.085s
sys	0m0.019s
```
#### spinlock_loop_sleep
to improve spinlock_loop_nothing, we add sleep(0) between each loop, sleep(0) means system maybe change current thread to sleep state.  
so, user time is low, but sys time is higher than spinlock_loop_nothing.  
but as a whole, spinlock_loop_sleep is better than spinlock_loop_nothing.  
logs bellow:
```
[case 3] spinlock_loop_sleep:

real	0m0.674s
user	0m0.492s
sys	0m0.257s
```
#### spinlock_loop_nanosleep
nanosleep vs sleep(0).
```
[case 4] spinlock_loop_nanosleep:

real	0m0.751s
user	0m0.676s
sys	0m0.238s
```
#### spinlock_webrtc(sched_yield)
spinlock_webrtc call sched_yield() in each loop.  
sched_yield() causes the calling thread to relinquish the CPU. The thread is moved to the end of the queue for its static priority and a new thread gets to run.  
sched_yield() is better than sleep, because sys time is low.
```
[case 5] spinlock_webrtc:

real	0m0.737s
user	0m0.799s
sys	0m0.082s
```
### protected scope consume much time
like cases bellow, do some memory operation in protected scope, that will cost much time.  

#### mutex_heavy_task
most of time runs in user time, like memory operations.  
sys time is low.  
```
[case 6] mutex_heavy_task:

real	0m3.377s
user	0m3.084s
sys	0m0.061s
```

#### spinlock_webrtc_heavy_task
sys time and user time are both much higher than mutex.  
so if protected scope will cost much time, mutex is better.
```
[case 7] spinlock_webrtc_heavy_task:

real	0m3.476s
user	0m5.742s
sys	0m0.491s
```
## stl
### map_vs_unordered_map(3 vs 1)
map's cost is about 3 times as unordered_map.
```
[case 1] map:

real	0m2.029s
user	0m1.784s
sys	0m0.030s

==========================
[case 2] unordered_map:

real	0m0.871s
user	0m0.619s
sys	0m0.028s

==========================
```

### vector
1. reserve < resize = ctor < push_back
2. reserve, resize, ctor has the same sys cost, because they malloc memory one time.
3. reserve's user cost is least, because reserve just allocate memory without call TestClass ctor.
but resize and vector_ctor allocate memory and call TestClass ctor.
4. push_back's sys cost is highest, because vector need reallocate memory while push_back if memory not enough.
5. push_back's user cost is higher than resize, but why?

```
[case 1] vector_push_back:

real	0m1.952s
user	0m1.396s
sys	0m0.433s

==========================
[case 2] vector_resize:

real	0m1.311s
user	0m1.050s
sys	0m0.144s

==========================
[case 3] vector_ctor:

real	0m1.305s
user	0m1.051s
sys	0m0.141s

==========================
[case 4] vector_reserve:

real	0m0.720s
user	0m0.462s
sys	0m0.142s

==========================
```