#include <stdio.h>
#include <x86intrin.h>

#define N 128
#define M N



short int a_short[N][M] __attribute__(( aligned(16)));
short int b_short[N][M] __attribute__(( aligned(16)));
unsigned short int temp[8];


int main()
{

	int i, j, ssd=0;
	__m128i ssd_temp1,ssd_temp2, ssd_total;

	ssd_total= _mm_setzero_si128();

	for(i=0; i<N; i++){
		ssd_temp1 = _mm_setzero_si128();
		for(j=0; j<M; j+=8){//IACA_START
			ssd_temp1  = _mm_sub_epi16 ( _mm_load_si128((__m128i *)&a_short[i][j]),  _mm_load_si128((__m128i *)&b_short[i][j]));
			ssd_temp2  = _mm_mullo_epi16(ssd_temp1, ssd_temp1);
			ssd_total = _mm_add_epi16 ( ssd_temp2, ssd_total);

		}//IACA_END
	}	
	asm("#kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");

	_mm_store_si128((__m128i *)&temp[0], ssd_total);//printVeci16s(ssd_total);
	ssd = temp[0]+temp[2]+temp[4]+temp[6] +temp[1]+temp[3]+temp[5]+temp[7];

	printf("%i", ssd);
	return 0;
}

