#include <stdio.h>

int fib(int rank)
{
   int first=1, second=1, third=2;
   if(rank<=2) return 1;
   else
   {
       while(rank-2)
       {
           rank--;
           third = first + second;
           printf("%d\n", third);
           first = second;
           second = third;
       }
       return third;
   }

}

int main()
{
    int i=0;
    fib(10);
    return 0;
}
