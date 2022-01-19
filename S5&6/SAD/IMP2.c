

#include <stdio.h>
#include <x86intrin.h>

#define N 128
#define M N


//global data for sequentila matrix operations
unsigned char a_char[N][M] __attribute__(( aligned(16))) = {{1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11}};
unsigned char b_char[N][M] __attribute__(( aligned(16))) = {{2,3,4,5,6,7,8,9,10,11,6,7,8,9,10,2,3,4,5,6,7,8}};
unsigned char c_char[N][M] __attribute__(( aligned(16)));
unsigned short int temp[16] __attribute__(( aligned(16)));


int main()
{


	int i, j, sad=0;
	
 	__m128i vec1, vec2, vecT, sad_total;
 	sad_total= _mm_setzero_si128();
		
		for(i=0; i<N; i++){
			//sad_temp= _mm_setzero_si128();
			for(j=0; j<M; j+=16){//IACA_START
					
					vec1 = _mm_load_si128((__m128i *)&a_char[i][j]);
					vec2 = _mm_load_si128((__m128i *)&b_char[i][j]);
					vecT = _mm_sad_epu8( vec1 , vec2);
					sad_total = _mm_add_epi64(vecT, sad_total);
				}//IACA_END
			}
		

			_mm_store_si128((__m128i *)&temp[0], sad_total);
			sad = temp[0]+temp[4];
	
		
	
	printf("%d \n", sad);
	return 0;
}

