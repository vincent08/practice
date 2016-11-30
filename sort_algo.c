#include<stdio.h>
#include<stdlib.h>

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


void  merge(int *array, int lo,int  mid,int hi, int *sorted_array)
{
    int i=lo, j=mid;
    int k=lo;
    while(i<mid && j<hi)
    {
        if(array[i]< array[j])
        {
            sorted_array[k]=array[i];
            k++;
            i++;
        }
        else
        {
            sorted_array[k]=array[j];
            k++;
            j++;
        }
    }
    if(i==mid) {
        while(j<hi) sorted_array[k++]=array[j++];
    }
    else {
        while(i<mid) sorted_array[k++]=array[i++];
    }
   printf("array1: ");
   print(array+lo, mid-lo);
   printf("array2: ");
   print(array+mid, hi-mid);
   printf("sorted array: ");
   print(sorted_array+lo, hi-lo);

   int index=lo;
   while(index<hi) { array[index] = sorted_array[index]; index++; }  // copy to space of original array.
}

void merge_sort(int *array, int lo, int hi, int *sorted_array)  // [lo, hi)
{
   if(hi-lo<2) return;
   int mid = (lo+hi)/2;
   merge_sort(array, lo, mid, sorted_array);
   merge_sort(array, mid, hi, sorted_array);
   merge(array, lo, mid, hi, sorted_array);
}

int main()
{
    int a[]={94,3,2,1,87,-3,99,100,100,102,34,-900, 19878, 230,-1};
    printf("The original array is:\n");
    print(a,15);
    //    select_sort(a,15);
//    quick_sort(a,0,14);
   int* sorted_array = (int *)malloc(sizeof(int)*15); 
    merge_sort(a,0,15, sorted_array);
    printf("The final array is:\n");
    print(a,15);
    free(sorted_array);
    return 0;
}
