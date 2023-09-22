#!/bin/bash
for((i=1;i<11;i++))
do
od -An -td1 -N1 < /dev/random >> numbers.txt
done