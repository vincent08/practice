#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
int atoi(const char *str)
{
    int res=0;
    int i=0;
    int flag=1;
    if(str[0]=='-') {flag=-1; i++;}
    while(str[i]!='\0')
    {
        assert(str[i]>='0' && str[i]<='9');
        if(flag==1 && INT_MAX/10<res) return INT_MAX;
        if(flag==-1 && INT_MIN/10>-res) return INT_MIN;
        res=res*10+str[i]-'0';
        i++;
    }

    return res*flag;
}


void itoa(int num, char *str)
{
    int i=0, flag=1;
    if(num<0){
        flag=-1;
        num=-num;
    }

    while(num>0)
    {
        str[i]= num%10 + '0';
        num/=10;
        i++;
    }

    int len=i;
    char tmp;

        i=0;
        while(i<len/2)
        {
           tmp = str[i];
           str[i] = str[len-i-1];
           str[len-i-1]=tmp;
           i++;
        }
    if(flag==-1)
    {
        int j=len;
        while(j>0)
        {
           str[j]=str[j-1];
           j--;    
        }
        str[j]='-';
    }
}


int main()
{
    printf("%d\n",atoi("99822222222222"));
    char *str=(char *)malloc(20);
    memset(str,0,20);
    itoa(-1902190219021902, str);
    printf("%s\n", str);
    return 0;
}
