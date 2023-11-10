#ifndef SUM_H
#define SUM_H

struct SumArgs {
  int *array;
  int begin;
  int end;
};


long long int Sum(const struct SumArgs *args);
void *ThreadSum(void *args);

#endif