//Matrix Multiplication  
#include <stdio.h>
#include <x86intrin.h>

#define MAX1 128
#define MAX2 MAX1
#define MAX3 MAX1

int __attribute__(( aligned(32))) a[MAX1][MAX2]  
  , __attribute__(( aligned(32))) b[MAX2][MAX3] 
  , __attribute__(( aligned(32))) c_result[MAX1][MAX3];
//

int main()
{
	

	int i, j, k;
	int temp8[8] __attribute__(( aligned(32)));
	
	__m256i vec_a, vec_b, vec_m, vec_sum;
	int __attribute__(( aligned(32))) vindexm [8]={0, MAX1, MAX1*2, MAX1*3, MAX1*4, MAX1*5, MAX1*6, MAX1*7 };
 	__m256i vindex = _mm256_load_si256((__m256i *) &vindexm[0]);
 	
		for( i=0;i<MAX1;i++){
			for(j=0;j<MAX3;j++){
				vec_sum = _mm256_setzero_si256();
				for(k=0;k<MAX2;k+=8)	{//IACA_START
					//temp += a[i][k] * c_tra[k][j];
					vec_a = _mm256_load_si256((__m256i *)&a[i][k]);
					vec_b = _mm256_i32gather_epi32 ((int const *)&b[k][j],vindex,4);
					vec_m = _mm256_mullo_epi32(vec_a, vec_b);
					vec_sum = _mm256_add_epi32(vec_m, vec_sum);
					
				}//IACA_END		
				_mm256_store_si256((__m256i *)&temp8[0] , vec_sum);
				c_result[i][j]= temp8[0]+temp8[1]+temp8[2]+temp8[3]+temp8[4]+temp8[5]+temp8[6]+temp8[7];

			}
		}
	
			
	return 0;
}
