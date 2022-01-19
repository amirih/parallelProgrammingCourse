
#include <stdio.h>
//#include <iacaMarks.h>


int main(){

	int a[16] = {1, 2, 3, 4, 5, 6, 7, 8}, b[16] = {9, 10, 11, 12, 13, 14, 15, 16}, c[16];
	
	int i=0;
	
	for(; i<16; i++)
		c[i] = a[i] + b[i];
		
	for(i=0; i<16; i++){//IACA_START
		printf("%d, ", c[i]);
	}//IACA_END
		
	printf("\n");
	

return 0;
}
