#include<stdio.h>

void bubble_sort(int *array, int len)
{
    int i=0, j=0;
    for(i=0; i<len; i++)
        for(j=0; j<i; j++)
    {
       if(array[j]>array[i])
       {
           array[j]=array[i]^array[j];
           array[i]=array[i]^array[j];
           array[j]=array[i]^array[j];
       }
    }
}

void select_sort(int *array, int len)
{
    int i=0, j=0;
    for(i=0; i<len; i++)
        for(j=i; j<len; j++)
    {
       if(array[j]<array[i])
       {
           array[j]=array[i]^array[j];
           array[i]=array[i]^array[j];
           array[j]=array[i]^array[j];
       }
    }
}

void insert_sort(int *array, int len)
{
    if(len<2) return;
    int i=0, j=0;
    int tmp=0;
    for(i=1; i<len; i++)
    {
        tmp = array[i];
        j=i-1;
        while(j>=0 && tmp < array[j])
        {
            if(tmp<array[j])
            {
                array[j+1]=array[j];
            }
            --j;
        }
              array[j+1]=tmp;

    }
}

void swap(int *array, int i, int j)
{
    if(i==j) return;
    array[i]=array[j]^array[i];
    array[j]=array[j]^array[i];
    array[i]=array[j]^array[i];
}

int partition(int *array, int left, int right, int pivot)
{
    swap(array, pivot, right);
    pivot = right;
    int flag=left;
    for(int i=left; i<=right-1; i++){
        if(array[i]<=array[pivot]){
            swap(array, i, flag);
            flag++;
        }
    }
    swap(array, pivot, flag);
    return flag;
}


void print(int *a, int len)
{
    int i=0;
    while(len--)
    {
        printf("%d  ", a[i++]);
    }
    printf("\n");
}
void quick_sort(int *array, int left, int right)
{
    print(array,15);
   if(left>=right) return;
   int pivot = partition(array, left, right, right);
   quick_sort(array, left, pivot-1);
   quick_sort(array, pivot+1, right);
}



int main()
{
    int a[]={94,3,2,1,87,-3,99,100,100,102,34,-900, 19878, 230,-1};
//    select_sort(a,15);
    quick_sort(a,0,14);
    print(a,15);
    return 0;
}
