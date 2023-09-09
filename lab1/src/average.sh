#!/bin/sh
len=$#
sum=0
for val in "$@"; do
    sum=$(($sum + $val))
done
avrg=$(($sum/$len))
expr "Кол-во аргументов $len"
expr "Cр.арефм. $avrg"