#include<cstdio>
#include "omp.h"
int main(int argc, char* argv[])
{

int nthreads, tid;
int nprocs;
char buuf[32];
	/* Forka team of threads */
#pragma omp parallel private(nthreads, tid)
{
 tid = omp_get_thread_num();
 printf("Hello World from OMP thread %d\n", tid);
 if(tid==0)
 {
 nthreads = omp_get_num_threads();
 printf("Number of thresds %d\n",nthreads);
 }
}
}
