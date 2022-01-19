#include <stdio.h>
#include <x86intrin.h>

#define N 8
#define M N
int  __attribute__(( aligned(16))) A[N][M] // ={{1,2,3,4,5,6,7,8},{},{},{},{},{8,7,6,5,4,3,2,1}}
	, __attribute__(( aligned(16))) A_T[N][M] ;



int main()
{

	int i, j;

 	__m128i row0, row1, row2, row3;
	__m128i __t0, __t1, __t2, __t3;
    for( i=0;i<N;i++){
        for(j=0;j<M;j++){//IACA_START
            A[i][j] = i+2;

        }//IACA_END
    }

	for( i=0;i<N;i+=4){
		for(j=0;j<M;j+=4){//IACA_START

			row0 = _mm_load_si128((__m128i *)&A[i][j]);
			row1 = _mm_load_si128((__m128i *)&A[i+1][j]);
			row2 = _mm_load_si128((__m128i *)&A[i+2][j]);
			row3 = _mm_load_si128((__m128i *)&A[i+3][j]);

			__t0 = _mm_unpacklo_epi32(row0, row1);
			__t1 = _mm_unpacklo_epi32(row2, row3);
			__t2 = _mm_unpackhi_epi32(row0, row1);
			__t3 = _mm_unpackhi_epi32(row2, row3);

			/* Assigning transposed values back into I[0-3] */
			row0 = _mm_unpacklo_epi64(__t0, __t1);
			row1 = _mm_unpackhi_epi64(__t0, __t1);
			row2 = _mm_unpacklo_epi64(__t2, __t3);
			row3 = _mm_unpackhi_epi64(__t2, __t3);

			_mm_store_si128((__m128i *)&A_T[j][i], row0);
			_mm_store_si128((__m128i *)&A_T[j+1][i], row1);
			_mm_store_si128((__m128i *)&A_T[j+2][i], row2);
			_mm_store_si128((__m128i *)&A_T[j+3][i], row3);



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
