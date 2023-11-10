#include "find_min_max.h"

#include <limits.h>

struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end) {
  struct MinMax min_max;
  min_max.min = INT_MAX;
  min_max.max = INT_MIN;

  // your code here
  int length=sizeof(array)/sizeof(array[0]);
  for (int i=0;i<length;++i)
    {
      if(array[i]>min_max.max)
      {
        min_max.max=array[i];
      }
      if(array[i]<min_max.min)
      {
        min_max.min=array[i];
      }
    }
  return min_max;
}
