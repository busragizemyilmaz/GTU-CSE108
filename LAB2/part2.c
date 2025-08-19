#include <stdio.h>

int main()
{
   float unit;
     
   printf("Enter the unit of consumed: ");
   scanf("%f", &unit);
     
   if(unit <= 50)
   {
      unit = unit * 0.5;
   }
     
   else if (unit > 50 && unit <= 100)
   {
      unit = (50 * 0.5) + ((unit - 50) * 0.75);
   }
     
   else if (unit > 100 && unit <= 250)
   {
      unit = (50 * 0.5) + (50 * 0.75) + ((unit - 100) * 1.20);
   }
     
   else
   {
      unit = (50 * 0.5) + (50 * 0.75) + (150 * 1.20) + ((unit - 250) * 1.50);    
   }
     
   unit = (unit * 120) / 100;
     
   printf("\nNet amount to be paid: %.0f\n", unit);
     
   return 0; 
}
