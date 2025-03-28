#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <windows.h>

int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void heavy_task(int thread_num) {
  for (int i = 0; i < 1e8; i++) {
    sqrt(i);
  }
  printf("\tThread #%d finished\n", thread_num);
}

void sequential(int threads_num) {

    for (int i = 0; i < threads_num; i++) {
        printf("MAIN: starting thread %d\n", i);
        heavy_task(i);
    }
}

int main(int argc, char** argv) {
  struct timespec start, end;
  if (argc < 2){
    printf("No arguments detected.\n");
    return 1;
  }

  SetConsoleOutputCP(65001);
  int threads_num = atoi(argv[1]);
  
  clock_gettime(CLOCK_MONOTONIC, &start);
  sequential(threads_num);
  clock_gettime(CLOCK_MONOTONIC, &end);

  
  double elapsed_ms = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1e6;
  printf("%d последовательных потоков за %.3f мс.\n",threads_num, elapsed_ms);
  return 0;
}