#include <stdio.h>
#define N 8
#define LEN  N*N //array size

int __attribute__(( aligned(32))) a[LEN] ;
int main(){
	int i, b, c;

    // b=1 and c=2 in this case
    b=1;
    c=2;
    a[0]=b;
	for(i=1; i<LEN; i++)
		a[i] = a[i-1] +c;

    for(i=1; i<LEN; i++)
		printf("%3d, ",a[i]);
	return 0;
}
