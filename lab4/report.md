### Задание №1

...
#### Решение
```
gcc parallel_min_max.c utils.c find_min_max.c -o ex_1_4
./ex_1_4 --seed "2" --array_size "50000000" --pnum "100" --timeout "1"
```
```
I killed them all!
```

### Задание №2

...

#### Решение
```
chmod u+x exampl_zomb.sh
./exampl_zomb.sh 
```
```
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root      3851  0.0  0.0      0     0 pts/0    Z+   12:42   0:00 [zomb] <defunct>
root      3853  0.0  0.1   6680  2220 pts/0    S+   12:43   0:00 grep Z
```

### Задание №3

...
#### Решение
```
gcc process_memory.c -o ex_3_4
./ex_3_4
```
```
Address etext: 9761A415 
Address edata: 9761D058 
Address end  : 9761D090 
ID main          is at virtual address: 9761A1A9
ID showit        is at virtual address: 9761A341
ID cptr          is at virtual address: 9761D050
ID buffer1       is at virtual address: 9761D070
ID i     is at virtual address: 66DCCB8C
A demonstration
ID buffer2       is at virtual address: 66DCCB68
Alocated memory at 978C96B0
This message is output by the function showit()
```
### Задание №4-6

...
#### Решение
```
make      
./parallel_sum --threads_num "1" --seed "2" --array_size "3"
```
```
gcc -I.   -c -o find_min_max.o find_min_max.c
gcc -I.   -c -o utils.o utils.c
gcc -o parallel_min_max find_min_max.o utils.o parallel_min_max.c -I.
gcc -I.   -c -o sum.o sum.c
gcc -o parallel_sum sum.o utils.o parallel_sum.c -lpthread
gcc -o process_memory process_memory.c -I.
```
```
./parallel_sum --threads_num "1" --seed "2" --array_size "3"
```
```
Total: -860178499
Elapsed time: 0.091000ms
```
