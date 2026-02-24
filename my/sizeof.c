#include <stdio.h>
#include <limits.h> // für int Typen
#include <float.h>  // für float Typen

int main(void)
{
    printf("Int Types:\n");

    printf("sizeof(char) =  %lu\n", sizeof(char));
    printf("sizeof(short) = %lu\n", sizeof(short));
    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(long) = %lu\n", sizeof(long));

    printf("FloatTypes:\n");

    printf("sizeof(float) = %lu\n", sizeof(float));
    printf("sizeof(double) = %lu\n", sizeof(double));
    return 0;
}