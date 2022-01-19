
#include <stdio.h>
#include <immintrin.h>



int main(){

	int __attribute__(( aligned(32))) a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 18}, b[16] = {9, 10, 11, 12, 13, 14, 15, 16, 14}, c[16] ;

	__m256i vec_a, vec_b, vec_c;

	int i=0;
	for(; i<16; i+=8){

		vec_a = _mm256_load_si256((__m256i *) &a[i]);
		vec_b = _mm256_load_si256((__m256i *) &b[i]);

		vec_c = _mm256_add_epi32(vec_a, vec_b);

		_mm256_store_si256((__m256i *) &c[i], vec_c);
	}

	i=0;
	for(i=0; i<16; i++)
		printf("%d, ", c[i]);

	printf("\n");




return 0;
}
