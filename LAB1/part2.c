#include <stdio.h>

int main()
{
   float W1;
   float W2;
   float W3;
   float P1;
   float P2;
   float P3;
   float T;
   float C;
  
   printf("Enter a first weight: ");
   scanf("%f", &W1);
   printf("Enter a second weight: ");
   scanf("%f", &W2);
   printf("Enter a third weight: ");
   scanf("%f", &W3);
   
   printf("\n");
   
   printf("Enter a first price per gram: ");
   scanf("%f", &P1);
   printf("Enter a second price per gram: ");
   scanf("%f", &P2);
   printf("Enter a third price per gram: ");
   scanf("%f", &P3);
   
   T = W1 + W2+ W3;
   C = (W1 * P1) + (W2 * P2) + (W3 * P3);
   
   printf("\nTotal weight of mixture is %.2f\n", T);
   printf("Cost of mixture is %.2f\n", C);
   
   return 0;
}
