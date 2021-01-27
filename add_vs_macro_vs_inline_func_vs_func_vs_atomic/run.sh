#! /bin/bash

cases=(add_+ add_macro add_inline_func add_func add_atomic)

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