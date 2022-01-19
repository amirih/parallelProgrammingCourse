#include <stdio.h>
#include <x86intrin.h>
#define N 8
#define LEN N*N  //array size
//for time measurements

int __attribute__(( aligned(32))) a[LEN];
int main(){


	int i, b, c;

    // b=1 and c=2 in this case
    b=1;
    c=2;
    i = 0;
    a[i++] = b;//0 --> a[0] = 1
    //step 1:
    //solving dependencies vectorization factor is 8
    a[i++] = a[0] + 1*c; //1  --> a[1] = 1 + 2  = 3
    a[i++] = a[0] + 2*c; //2  --> a[2] = 1 + 4  = 5
    a[i++] = a[0] + 3*c; //3  --> a[3] = 1 + 6  = 7
    a[i++] = a[0] + 4*c; //4  --> a[4] = 1 + 8  = 9
    a[i++] = a[0] + 5*c; //5  --> a[5] = 1 + 10 = 11
    a[i++] = a[0] + 6*c; //6  --> a[6] = 1 + 12 = 13
    a[i++] = a[0] + 7*c; //7  --> a[7] = 1 + 14 = 15
    // vectorization factor reached
    // 8 *c will work for all
    //loading the results to an vector
    __m256i dep1;
    __m256i  dep2; //  dep = { 1,  3,  5, 7,  9,  11, 13, 15 }
    __m256i coeff = _mm256_set1_epi32(8*c); //coeff = { 16, 16, 16, 16, 16, 16, 16, 16 }

    for(; i<LEN; i+=8){

        dep1 = _mm256_load_si256((__m256i *) &a[i-8]);
        dep1 = _mm256_add_epi32(dep1, coeff);
        _mm256_store_si256((__m256i *) &a[i], dep1);

    }

     for(i=0; i<LEN; i++){
		if(!(i%8))
            printf("\n");
        printf("%3d, ",a[i]);
     }


	return 0;
}
