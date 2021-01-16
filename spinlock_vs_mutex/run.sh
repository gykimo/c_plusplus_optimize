#! /bin/bash

cases=(mutex spinlock_loop_nothing spinlock_loop_sleep spinlock_loop_nanosleep spinlock_webrtc mutex_heavy_task spinlock_webrtc_heavy_task)

i=1

echo

for case in ${cases[*]}
do
    rm $case
    g++ -o $case -std=c++11 $case.cpp
    echo [case $i] $case:
    time ./$case
    echo
    echo ==========================

    i=$(($i+1))
done

echo