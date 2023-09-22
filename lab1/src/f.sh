#!/bin/bash
sum=0
x=0
count=0
while IFS= read -r line
do
  sum=$[sum+$line]
  count=$[count+1]
done < numbers.txt
echo "$count"
x=$[$sum/$count]
echo "$x"
