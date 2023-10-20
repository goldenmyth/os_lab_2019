###Задание №1

Написать функцию GetMinMax в find\_max\_min.c, которая ищет минимальный и максимальный элементы массива, на заданном промежутке.
Разобраться, что делает программа в sequiential\_min\_max.c, скомпилировать, проверить, что написанный вами GetMinMax работает правильно.

####Решение
```
gcc  find_min_max.c  utils.c sequential_min_max.c -o ex_1
./ex_1 2 10
>>min: 142559277
>>max: 1738766719
```

###Задание №2-3

Завершить программу parallel\_min\_max.c, так, чтобы задача нахождения минимума и максимума в массиве решалась параллельно.
Если выставлен аргумент `by_files` для синхронизации процессов использовать файлы (задание 2), в противном случае использовать pipe (задание 3).

####Решение
```
gcc parallel_min_max.c utils.c find_min_max.c -o ex_2_3
./ex_2_3 --seed "2" --array_size "20" --pnum "4"
>>Min: 142559277
>>Max: 2127304342
>>Elapsed time: 0.465000ms
./ex_2_3 --seed "2" --array_size "20" --pnum "4" --by_files
>>Min: 142559277
>>Max: 2127304342
>>Elapsed time: 0.964000ms
```

###Задание №4

Изучить все targets в makefile, будьте готовы объяснить, за что они отвечают. Используя `makefile`, собрать получившиеся решения. Добавьте target `all`, отвечающий за сборку всех программ.

####Решение
```
make
>>gcc -o utils.o -c utils.c -I.
>>gcc -o find_min_max.o -c find_min_max.c -I.
>>gcc -o sequential_min_max find_min_max.o utils.o sequential_min_max.c -I.
>>gcc -o parallel_min_max utils.o find_min_max.o parallel_min_max.c -I.
>>gcc -o ex5 ex5.c -I.
>>chmod u+x ex5
./sequential_min_max 2 10
>>min: 142559277
>>max: 1738766719
./parallel_min_max --seed "2" --array_size "10" --pnum "2"
>>Min: 142559277
>>Max: 1738766719
>>Elapsed time: 0.442000ms
```

###Задание №5

Написать программу, которая запускает в отдельном процессе ваше приложение sequiential\_min\_max. Добавить его сборку в ваш makefile.

####Решение
```
make
>>gcc -o utils.o -c utils.c -I.
>>gcc -o find_min_max.o -c find_min_max.c -I.
>>gcc -o sequential_min_max find_min_max.o utils.o sequential_min_max.c -I.
>>gcc -o parallel_min_max utils.o find_min_max.o parallel_min_max.c -I.
>>gcc -o ex5 ex5.c -I.
>>chmod u+x ex5
./ex5 2 10
>>min: 142559277
>>max: 1738766719
```