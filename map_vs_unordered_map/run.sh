#! /bin/bash

cases=(map unordered_map)

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