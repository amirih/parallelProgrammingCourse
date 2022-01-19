#include <stdio.h>
#define N 128
#define M N

short int a_short[N][M] __attribute__(( aligned(32)));
short int b_short[N][M] __attribute__(( aligned(32)));


int main()
{

	int i, j, ssd=0;


	for(i=0; i<N; i++){
		for(j=0; j<M; j++){//IACA_START
			ssd+= ((a_short[i][j]-b_short[i][j]))*((a_short[i][j]-b_short[i][j]));
		}//IACA_END
	}


		
	return ssd;
}

