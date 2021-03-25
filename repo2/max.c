#include <stdio.h>
#define SIZE 100000
int Max(int *p,int n)
{
    int m;
    if(n<1){
        printf("参数错。\n");
        return -1;
    }
    if(n==1) m=*p;
    else{
        m=Max(p+1,n-1);
        if(*p>=m) 
            return *p;
        else                 
            return m;
    }
}
int main()
{
    int a[SIZE],n,i,max;
    printf("输入正整数n：");
    scanf("%d",&n);
    printf("输入n个整数：\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max=Max(a,n);
    printf("max=%d\n",max);
    return 0;
}