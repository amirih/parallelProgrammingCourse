#include <stdio.h>
#include <x86intrin.h>

#define N 8
#define M N


int  __attribute__(( aligned(32))) A[N][M]
	, __attribute__(( aligned(32))) A_T[N][M] ;



int main()
{

	int i, j;
		// variables for vector section
 	int vindexm [8]={0, N, N*2, N*3, N*4, N*5, N*6, N*7 };
 	__m256i vindex = _mm256_load_si256((__m256i *) &vindexm[0]);
 	__m256i vec1, vec2, vec3, vec4, vec5, vec6, vec7, vec8;
    for( i=0;i<N;i++){
        for(j=0;j<M;j++){//IACA_START
            A[i][j] = i+2;

        }//IACA_END
    }

	for(i=0; i<N;  i+=8){
			for(j=0; j<M;  j+=8){//IACA_START

				//loading from columns
				vec1 = _mm256_i32gather_epi32 ((int const *)&A[i][j+0],vindex,4);
				vec2 = _mm256_i32gather_epi32 ((int const *)&A[i][j+1],vindex,4);
				vec3 = _mm256_i32gather_epi32 ((int const *)&A[i][j+2],vindex,4);
				vec4 = _mm256_i32gather_epi32 ((int const *)&A[i][j+3],vindex,4);
				vec5 = _mm256_i32gather_epi32 ((int const *)&A[i][j+4],vindex,4);
				vec6 = _mm256_i32gather_epi32 ((int const *)&A[i][j+5],vindex,4);
				vec7 = _mm256_i32gather_epi32 ((int const *)&A[i][j+6],vindex,4);
				vec8 = _mm256_i32gather_epi32 ((int const *)&A[i][j+7],vindex,4);

				//storing to the rows
				_mm256_store_si256((__m256i *)&A_T[j+0][i], vec1);
				_mm256_store_si256((__m256i *)&A_T[j+1][i], vec2);
				_mm256_store_si256((__m256i *)&A_T[j+2][i], vec3);
				_mm256_store_si256((__m256i *)&A_T[j+3][i], vec4);
				_mm256_store_si256((__m256i *)&A_T[j+4][i], vec5);
				_mm256_store_si256((__m256i *)&A_T[j+5][i], vec6);
				_mm256_store_si256((__m256i *)&A_T[j+6][i], vec7);
				_mm256_store_si256((__m256i *)&A_T[j+7][i], vec8);


			}//IACA_END//ii++;
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
