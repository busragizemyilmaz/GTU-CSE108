#include <stdio.h>

int main()
{
    int A = 12;
    int B = 4;
    int C = 3;
    int D = 8;
    int E = 2;
    int F = 17;
    int G = 5;
    int H = 6;
    int I = 2;
    float Z;
    
    Z = ((A + (B * C) - D) / E) + (F % G) - (H * I);
    
    printf("Z is %.2f\n", Z);
    
    return 0;
}
