#include <stdio.h>
#include <x86intrin.h>

#define N 128
#define M N

//global data for sequentila matrix operations
unsigned char a_char[N][M] __attribute__(( aligned(32))) = {{1,2,3,4,5,6,7,8,9,10,2,3,4,5,6,7,8,9,10,11}};
unsigned char b_char[N][M] __attribute__(( aligned(32))) = {{2,3,4,5,6,7,8,9,10,11,6,7,8,9,10,2,3,4,5,6,7,8}};
unsigned char c_char[N][M] __attribute__(( aligned(32)));
unsigned short int tempu16[16] __attribute__(( aligned(32)));


int main()
{

	int i, j, sad=0;

	__m256i vec1, vec2, vecT, sad_total;
	sad_total= _mm256_setzero_si256();

	for(i=0; i<N; i++){
		for(j=0; j<M; j+=32){//IACA_START

			vec1 = _mm256_load_si256((__m256i *)&a_char[i][j]);
			vec2 = _mm256_load_si256((__m256i *)&b_char[i][j]);
			vecT = _mm256_sad_epu8( vec1 , vec2);
			sad_total = _mm256_add_epi32(vecT, sad_total);

		}//IACA_END
	}

	_mm256_store_si256((__m256i *)&tempu16[0], sad_total);
	sad = tempu16[0]+tempu16[4]+tempu16[8]+tempu16[12];

	printf("%d \n", sad);
	return 0;
}

