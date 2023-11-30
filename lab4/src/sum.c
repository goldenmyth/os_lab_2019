#include "sum.h"

int Sum(const struct SumArgs *args) {
  uint64_t sum = 0;
  for (int i = args->begin; i < args->end; i++){
    sum += args->array[i];
  }
  return sum;
}

void *ThreadSum(void *args) {
  struct SumArgs *sum_args = (struct SumArgs *)args;
  return (void *)(uint64_t)Sum(sum_args);
}