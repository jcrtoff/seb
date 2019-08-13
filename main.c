#include <stdio.h>
#include <math.h>

//Mark 1
int getNewValue(double oldMin, double oldMax, double newMin, double newMax, int oldValue)
{
   double oldRange = (oldMax - oldMin);
   double newRange = (newMax - newMin);
   double newValue = ((((double)oldValue - oldMin) * newRange) / oldRange) + newMin;
   return round(newValue);
}

int translateNumber(const int oldValue)
{

   double newValue = 0;

   if(oldValue <= 1000)
      newValue = -400.0;
   else if(oldValue < 1500)
      newValue = getNewValue(1000.0, 1499.0, -400.0, -12.0, oldValue);
   else if (oldValue == 1500)
      newValue = 0.0;
   else if (oldValue <= 2000)
      newValue = getNewValue(1501.0, 2000.0, 12.0, 400.0, oldValue);
   else
      newValue = 400.0;

   return (int)newValue;
}
//Mark 2

void unitTest(int input, int expectation)
{

   printf("-----------------------------\n");
   printf("%d should become %d\n",input, expectation);

   int output = translateNumber(input);
   if(expectation == output)
      printf("\x1B[32mSuccess\x1B[0m");
   else
      printf("\x1B[31mFailure. %d was computed\x1B[0m", output);
   printf("\n");
   printf("\n");
}

int main()
{

   unitTest(-100, -400);
   unitTest(0, -400);
   unitTest(1000, -400);
   unitTest(1001, -399);
   unitTest(1250, -206);
   unitTest(1499, -12);
   unitTest(1500, 0);
   unitTest(1501, 12);
   unitTest(1750, 206);
   unitTest(1999, 399);
   unitTest(2000, 400);
   unitTest(2001, 400);
   unitTest(4000, 400);

   return 0;
}



