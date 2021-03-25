#include <stdio.h>
#define SIZE 100000
long Sum(int n)
{
    long y;
    if(n<1){
        printf("参数错。\n");
        return -1;
    }
    if(n==1) return 1;
    else {
        y=n+Sum(n-1);
        return y;
    }
}
int main()
{
    int i,n,a[SIZE];
    long sum;
    printf("输入正整数n：");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
    sum=Sum(n);
    if(n==1)      printf("1=1\n");
    else if(n==2) printf("1+2=3\n");
    else if(n==3) printf("1+2+3=6\n");
    else if(n>3)  printf("1+2+3+...+%d=%ld\n",n,sum);
    return 0;
}