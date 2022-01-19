#include <stdio.h>
#include <x86intrin.h>

#define len 100000

int a[len];
int b[len];
int c[len];
int main(){

    int i=0, w=0;

    long long t1, t2, tbest=9999999999999;

    do{
        t1 = _rdtsc();

        #pragma omp simd
        for (i=0; i<len; i++){
            c[i]= a[i] + b[i];

        }
        t2 = _rdtsc();
        if ((t2-t1) <tbest)
            tbest = t2-t1;

    }while (w++<1000);

    printf ("%ld", tbest);

    return 0;

}
