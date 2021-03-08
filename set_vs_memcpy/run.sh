#! /bin/bash

cases=(array_loop_set array_set mem_cpy class_attr_set class_attr_cpy)

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