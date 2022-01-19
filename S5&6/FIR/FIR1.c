#include "stdio.h"
//finite impulse response (FIR)

//numbers
#define N 100
#define NN N*N
#define COEFF 8




//global data for sequentila matrix operations
int __attribute__(( aligned(32))) input[NN+COEFF];			//= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
int __attribute__(( aligned(32))) output[NN];
int __attribute__(( aligned(32))) coeff[COEFF] = {1,2,3,4,5,6,7,8};//= {1,1,1,1,1,1,1,1};//;			//= {1,2,1,2,1,2,1,2,2,1};



int main()
{

	int i, j;


		for(i = 0; i < NN; i++){
			for(j = 0; j < COEFF; j++){//IACA_START
				output[i] += coeff[j] * input[i+j];

			}//IACA_END
		}


	return 0;
}

