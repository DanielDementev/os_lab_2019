#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



#include <getopt.h>
#include "utils.h"
#include <stdbool.h>
#include <sys/time.h>
#include <pthread.h>

#include "sum.h"




int main(int argc, char **argv) {
  /*
   *  TODO:
   *  threads_num by command line arguments
   *  array_size by command line arguments
   *	seed by command line arguments
   */
  uint32_t threads_num = 0;
  uint32_t array_size = 0;
  uint32_t seed = 0;
  pthread_t threads[threads_num];
 

    static struct option options[] = {{"threads_num", required_argument, 0, 0},
                                      {"seed", required_argument, 0, 0},
                                      {"array_size", required_argument, 0, 0},                   
                                      {0, 0, 0,0}};
while (true) {
    int option_index = 0;
    int c = getopt_long(argc, argv, "f", options, &option_index);

    if (c == -1) break;

    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            threads_num = atoi(optarg);
            // your code here
            // error handling
            if (threads_num <= 0) {
              printf("seed is a positive number\n");
              return 1;
            }
            break;
          case 1:
            seed = atoi(optarg);
            // your code here
            // error handling
            if (seed <= 0) {
              printf("array_size is a positive number\n");
              return 1;
            }
            break;
          case 2:
            array_size= atoi(optarg);
            // your code here
            // error handling
            if(array_size<=0)
            {
              printf("pnum is a positive number\n");
              return 1;
            }
            break;
          

          default:
            printf("Index %d is out of options\n", option_index);
        }
        break;
      

      case '?':
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }

  if (optind < argc) {
    printf("Has at least one no option  argument\n");
    return 1;
  }

  if (seed == -1 || array_size == -1 || threads_num == -1) {
    printf("Usage: %s --threads_num \"num\" --seed \"num\" --array_size \"num\" \n",
           argv[0]);
    return 1;
  }

  

  /*
   * TODO:
   * your code here
   * Generate array here
   */

  int *array = malloc(sizeof(int) * array_size);

  GenerateArray(array,array_size,seed);


  struct timeval start_time;
  gettimeofday(&start_time,NULL);
  struct SumArgs args[threads_num];
  args[0].begin=0;

  for (uint32_t i = 0; i < threads_num; i++) {
    args[i].array=array;
    if(i!=0)
    {
      args[i].begin=args[i-1].end;
    }
    if(array_size==args[i].begin)
      break;
    if(i!=threads_num)
    {
      args[i].end=(i+1)*array_size/threads_num;
    }
    else
    {
      args[i].end=array_size;
    }
    if (pthread_create(&threads[i], NULL, ThreadSum, (void *) (args+i))) {
      printf("Error: pthread_create failed!\n");
      return 1;
    }
  }

  long long int total_sum = 0;
  for (uint32_t i = 0; i < threads_num; i++) {
    long long int sum = 0;
    pthread_join(threads[i], (void **)&sum);
    total_sum += sum;
  }

  struct timeval finish_time;
  gettimeofday(&finish_time,NULL);

  double elapsed_time=(finish_time.tv_usec-start_time.tv_usec)/1000.0; 

  free(array);
  printf("Total: %lld\n", total_sum);
  printf("Время %f",elapsed_time);
  return 0;
}
