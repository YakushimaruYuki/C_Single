#include <stdio.h>
#define SIZE 10 
int main()
{
    double d[SIZE][SIZE],result=0;
    int r,c,n;
    printf("input order of determinant:(2 or 3)");
    scanf("%d",&n);
    printf("input determinant of order %d:\n",n);
    for(r=0;r<n;r++){
        for(c=0;c<n;c++){
            scanf("%lf",&d[r][c]);
        }
    }
    if(n==2){
        result=d[0][0]*d[1][1]-d[0][1]*d[1][0];
    }
    if(n==3){
        result=d[0][0]*d[1][1]*d[2][2]+d[0][1]*d[1][2]*d[2][0]+d[0][2]*d[1][0]*d[2][1]-d[0][2]*d[1][1]*d[2][0]-d[0][1]*d[1][0]*d[2][2]-d[0][0]*d[1][2]*d[2][1];
    }
    printf("result of determinant of order %d:\n",n);
    printf("%lf\n",result);
    return 0;
}