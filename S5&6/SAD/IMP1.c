
#include <stdio.h>


#define N 128
#define M N
//global data for sequentila matrix operations
unsigned char a_char[N][M] __attribute__(( aligned(32)));//= {{1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11}};
unsigned char b_char[N][M] __attribute__(( aligned(32)));// = {{2,3,4,5,6,7,8,9,10,11,6,7,8,9,10,2,3,4,5,6,7,8}};
unsigned char c_char[N][M] __attribute__(( aligned(32)));


int main()
{

	int i, j, sad=0;




		for(i=0; i<N; i++){
			for(j=0; j<M; j++){//IACA_START
                //(C?S:T)
				sad+= (((a_char[i][j]-b_char[i][j]<0))?-1*(a_char[i][j]-b_char[i][j]):(a_char[i][j]-b_char[i][j]));
			}//IACA_END
		}


	return sad;
}

