#include <stdio.h>
int main()
{
    int i,j=0,n,A[20000],LenRecord[20000],len=1,maxlen;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    for(i=1;i<n;i++){
        if(A[i]==A[i-1]+1){
            len++;
        }           
        if((A[i]!=A[i-1]+1)&&(len!=1)){
            LenRecord[j]=len;
            j++;
            len=1;
        }
    }
    LenRecord[j]=len;
    j++;
    maxlen=LenRecord[0];
    for(i=0;i<j;i++){
        if(LenRecord[i]>maxlen) maxlen=LenRecord[i];
    }
    printf("%d",maxlen);
}
