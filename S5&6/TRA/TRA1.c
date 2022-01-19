
#include <stdio.h>

#define N 8
#define M N
int __attribute__(( aligned(32))) A[N][M]
, __attribute__(( aligned(32))) A_T[N][M] ;

int main()
{

	int i, j;
	for( i=0;i<N;i++){
			for(j=0;j<M;j++){//IACA_START
				A[i][j] = i+2;

			 }//IACA_END
		}

		for( i=0;i<N;i++){
			for(j=0;j<M;j++){//IACA_START
				A_T[j][i] = A[i][j];

			 }//IACA_END
		}
        printf("\nMatrix:\n");
		for( i=0;i<N;i++){
            printf("\n");
			for(j=0;j<M;j++){//IACA_START
				printf("%4d", A[i][j]);

			 }//IACA_END
		}

        printf("\n\nTransposed Matrix:\n");
		for( i=0;i<N;i++){
            printf("\n");
			for(j=0;j<M;j++){//IACA_START
				printf("%4d", A_T[i][j]);

			 }//IACA_END
		}

	return 0;
}
