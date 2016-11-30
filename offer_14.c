#include<stdio.h>
#include<stdlib.h>

void sort_odd(int *array, int len)
{
    if(array == NULL || len <=0) return;
    int i=0, j=0, tmp=0;
    for(i=0; i<len; i++)
    {
        if(array[i]%2!=0)
        {
          tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
          j++;
        } 
    }

}

void print(int *array, int len)
{
    printf("\narray: ");
    for(int i=0; i<len; i++)
        printf("%d ", array[i]);
}

int main()
{
    int a[]={3};
    print(a,1);
    sort_odd(a,1);
    print(a,1);

    return 0;
}
