/*程序功能：编写一个程序，比较两个文本文件a1.txt和a2.txt的内容是否相同，若相同则输出“YES”，否则输出“NO”，
并输出两个文件内容首次不同的行号和字符位置。*/
#include <stdio.h>
#include <stdlib.h>
int compareFile(FILE *fp1,FILE *fp2,int *line,int *col)   
/*函数功能：比较两个文本文件是否相同，相同返回1，不同返回0*/
{
    char ch1,ch2;                       /*两文件都未结束则进入循环*/
    while((ch1=fgetc(fp1))!=EOF&&(ch2=fgetc(fp2))!=EOF){  
        if(ch1=='\n')                   /*换行时，行号加1，字符位置归0*/
        {
            (*line)++;
            (*col)=0;
        }
        if(ch1!=ch2) return 0;          /*对应字符有不同，返回0*/
        (*col)++;                       /*每次循环，字符位置加1*/
    }
    if(ch1==EOF&&ch2==EOF) return 1;    /*同时结束，返回1*/
    else return 0;                      /*不是同时结束，返回0*/
}
int main()
{
    FILE *fp1,*fp2;
    int line=1,col=0;
    if((fp1=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\bin\\a1.txt","r"))==NULL){    /*打开文件*/
        printf("不能打开该文件\n");
        exit(0);
    }
    if((fp2=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\bin\\a2.txt","r"))==NULL){
        printf("不能打开该文件\n");
        exit(0);
    }
    if(compareFile(fp1,fp2,&line,&col)==1) printf("YES");  /*内容相同，输出YES*/
    else printf("NO\n%d %d",line,col);                     /*内容不同，输出NO和行号、字符位置*/
    if(fclose(fp1)){                                       /*关闭文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    if(fclose(fp2)){
        printf("不能正常关闭文件\n");
        exit(0);
    }
    return 0;
}