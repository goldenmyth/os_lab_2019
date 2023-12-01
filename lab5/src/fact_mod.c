#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <pthread.h>
#include <getopt.h>

struct beg_end {
  int begin;
  int end;
};

void *ThreadMul(void *args);
int total_mul = 1;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv) {

  int k = -1;
  int pnum = -1;
  int mod = -1;
  while (true) {
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"pnum", required_argument, 0, 0},
                                      {"mod", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    int c = getopt_long(argc, argv, "k:", options, &option_index);
    if (c == -1) break;
    switch (c) {
      case 0:
        switch (option_index) {
          case 0:
            pnum = atoi(optarg);
            if (pnum <= 0) { 
              printf("pnum: %d cannot be negative\n", pnum); 
              return -1; 
            }
            break;
          case 1:
            mod = atoi(optarg);
             if (mod <= 0) { 
              printf("mod: %d cannot be negative\n", mod); 
              return -1; 
            }
            break;

          defalut:
            printf("Index %d is out of options\n", option_index);
        }
        break;
      case 'k':
        k = atoi(optarg);
        if (k <= 0) { 
            printf("k: %d cannot be negative\n", k);
            return -1;
        }
        break;
      case '?':
        break;

      default:
        printf("getopt returned character code 0%o?\n", c);
    }
  }
  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (k == -1 || pnum == -1 || mod == -1) {
    printf("Usage: %s -k \"num\" --pnum \"num\" --mod \"num\" \n",
           argv[0]);
    return 1;
  }

  pthread_t threads[pnum];
  struct beg_end args[pnum];
  args[0].begin = 1;
  for (uint32_t i = 0; i < pnum; i++) {
      if (i != 0){
          args[i].begin = args[i-1].end;
      }
      args[i].end = (i + 1) * k / pnum;
      if(args[i].begin == k){ break; }
      if (pthread_create(&threads[i], NULL, ThreadMul, (void *) &args[i])) {
      printf("Error: pthread_create failed!\n");
      return 1;
      }
  }

  for (uint32_t i = 0; i < pnum; i++) {
      pthread_join(threads[i], NULL);
  }
  
  printf("Factorial %d = %d\n", k, total_mul);
  printf("Factorial %d (mod %d) = %d\n", k, mod, total_mul % mod);

  pthread_mutex_destroy(&mut);
}

void *ThreadMul(void *args) {
  struct beg_end *begend = (struct beg_end *)args;
  int total = 1;
  
  for(int i = begend->begin; i < begend->end; ++i){
    total *= (i + 1);
  }
  pthread_mutex_lock(&mut);
  total_mul *= total;
  pthread_mutex_unlock(&mut);
}