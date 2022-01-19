//Scalar, Matrix addition, 8-12-2020
#include <stdio.h>
#include <x86intrin.h>
//Matrix dimension
#define N 128
#define M N

int A[N][M], B[N][M], C[N][M];

int main(){

	long t1,t2,tBest=99999999999999999;


	int i,j, w=0;
	//assigne data
	for(i=0; i<N; i++)
		for(j=0; j<M; j++){
			A[i][j]=i+j;
			B[i][j]=i*j;
	}

	//add two matrices

	do{
		t1= _rdtsc();
		for(j=0; j<M; j++)
			for(i=0; i<N; i++)//changed
				C[i][j] = A[i][j] + B[i][j];
		t2=_rdtsc();

		if(tBest > (t2-t1))
			tBest = t2-t1;

	}while(++w<1000);
	printf("%li\n", tBest);



	//print
	//printf("\nA:\n");
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			//printf("%4d, ", A[i][j]);
		}
		//printf("\n");
	}

	//printf("\nB:\n");
	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			//printf("%4d, ", B[i][j]);
		}
		//printf("\n");
	}

	//print the output
	//printf("\nC:\n");

	for(i=0; i<N; i++){
		for(j=0; j<M; j++){
			//printf("%4d, ", C[i][j]);
		}
		//printf("\n");
	}


return 0;
}
