#! /bin/bash

good=pointerset
bad=valueset

echo

rm $good
g++ -o $good -std=c++11 $good.cpp
echo good: $good
time ./$good

echo
echo ==========================
echo

rm $bad
g++ -o $bad -std=c++11 $bad.cpp
echo bad: $bad
time ./$bad

echo