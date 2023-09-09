#!/bin/bash
len=$#
sum=0

for val in "$@"; do
sum=$(($sum+$val))
done
avrg=$(($sum/$len))
echo $sum
echo $avrg
echo $#