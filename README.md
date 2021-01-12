# c_plusplus_optimize
summarize optimize methods for c/c++.  
please watch 'user' and 'sys' cost time.  
how to run: cd one case dir, and excute ./run.sh, then will print cost logs.  

主要总结一些C、C++的优化方法。  
耗时对比主要看user和sys两个耗时对比。  
进入每个示例，直接执行./run.sh，就可以打印出相应的对比log。 

# cases
## pointerset_vs_valueset
pointerset is bettet than valueset, about more than 50% improvement.

good: pointerset

real	0m0.428s
user	0m0.220s
sys	0m0.002s

==========================

bad: valueset

real	0m0.711s
user	0m0.499s
sys	0m0.004s

