#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void violent(char *S, char *P)
{
    int i=0, j=0;
    int begin=0;
    while(S[i] != '\0')
    {
       while(P[j] != '\0')
       {
           if(S[i] == '\0') break;
           else if(S[i]==P[j]){
               i++;
               j++;
           }
           else{
               i = i-j+1;
               begin = i;
               j = 0;
           }
       }
       if(P[j] == '\0') printf("found at index: %d\n", begin);
       j = 0;
    }
}


void buildnext(char *P, int *next)
{
   int len = strlen(P);
   int i=0;
   for(i=0; i<len; i++) next[i]=-1;
   int j=0;
   int k=0;
   while(j<len)
   {
       while(k<j)
       {

       }

       j++;
   }
}


int main()
{
    char S[]="Hello, my name is Lilei. My name is Hanmeimei.Nice to meet you!";
    char P[]="name";
    printf("%s\n%s\n", S, P);
    violent(S, P);
    return 0;
}
