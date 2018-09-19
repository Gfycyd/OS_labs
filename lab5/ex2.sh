#!/bin/bash

echo 777 > "ex2.txt"

if ln "ex2.txt" "ex2.txt".lock
then
  for i in {1..7};
  do
    last_num=`tail  -1 "ex2.txt"`
    last_num=$((last_num+1))
    echo $last_num >> "ex2.txt"
  done
rm "ex2.txt".lock
fi
