// compile: gcc helloWorldOMP.c -o helloWorldOMP -lm -fopenmp
//
// run: helloWorldOMP
//

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define T 4

int main( int argc, char *argv[] )
{
	int thread_num, nthread, soma=0;
	thread_num = omp_get_thread_num();
	nthread = omp_get_num_threads();
	printf("Hello world da thread master (região sequencial): %d. Num threads = %d", thread_num, n_threads);
	#pragma omp parallel private (thread_num, nthreads) num_threads(T) reduction(+:soma)
	{
		thread_num = omp_get_thread_num();
		nthread = omp_get_num_threads();
		soma = thread_num;
		printf("Hello world da thread %d na região paralela. Num threads = %d", thread_num, n_threads);
	}
	thread_num = omp_get_thread_num();
	nthread = omp_get_num_threads();
	printf("Região sequencial: thread_num = %d, Num_threads=%d, soma = %d", thread_num, n_threads, soma);

	return 0;

}
// diretivas básicas: parallel, for, section, single, critical, ...
// DIRETIVAS:
// * parallel:
//  permite criar regiões paralelas
//  #pragma omp parallel
//  a thread já existente se torna a thread #0



