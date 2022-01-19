//Matrix Multiplication Transposed  
#include <stdio.h>

#define MAX1 128
#define MAX2 MAX1
#define MAX3 MAX1

int __attribute__(( aligned(32))) a[MAX1][MAX2]  
  , __attribute__(( aligned(32))) b[MAX2][MAX3] 
  , __attribute__(( aligned(32))) c_result[MAX1][MAX3] 
  , __attribute__(( aligned(32))) c_tra[MAX3][MAX2];

//

int main()
{
	

	int i, w=0,j, k, temp;

		//transpose:
		for( i=0;i<MAX2;i++){
			for(j=0;j<MAX3;j++){//IACA_START
				c_tra[j][i] = b[i][j];

			 }//IACA_END
		}
		do{
		//Multiplication
		for( i=0;i<MAX1;i++){
			for(j=0;j<MAX3;j++){
				temp=0;
				for(k=0;k<MAX2;k++)	{//IACA_START
					temp += a[i][k] * c_tra[j][k];
				}//IACA_END		
				c_result[i][j] = temp;

			}
		}
		}while (w++ <10000);
			
	return 0;
}
