#include<stdio.h>

int binary_search(int *array, const int e, int lo, int hi)
{// [lo,hi)
  if(lo>=hi) return -1;
  int  mid = (lo+hi)>>1;
  if(array[mid]<e) return binary_search(array, e, mid+1, hi);
  else if(e<array[mid]) return binary_search(array, e, lo, mid);
  else return mid;

}


int binary_search_2(int *array, const int e, int lo, int hi)
{
    int mid=0;
    while(lo<hi){
        mid = (lo+hi)>>1;
        if(array[mid]==e) return mid;
        else if(array[mid]>e) hi=mid+1;
        else lo=mid;
    }
    return -1;
}


int main()
{
    int a[]={1,2,3,4,5,6,90,91,293};
    int rank = binary_search_2(a,4,0,9);
    printf("the rank: %d\n", rank);
    return 0;
}
