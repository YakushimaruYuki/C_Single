/*程序功能：已知文件 a.txt 存储若干文本数据，编程统计 a.txt 文件的行数、大写字母个数、小写字母个数、数字字符个数及其他字符的个数。要求如下：
① 定义 countFile()函数：统计文本文件的行数、大写字母个数、小写字母个数、数字字符个数及其他字符的个数。     ② 定义 main()函数：打开 a.txt 文件，
调用 countFile()函数统计文本文件的行数、大写字母个数、小写字母个数、数字字符个数及其他字符的个数，输出统计结果。 */
#include <stdio.h>
#include <stdlib.h>
void countFile(FILE *fp)                         
/*函数功能：统计各字符个数，输出统计结果*/
{
    int lines=1,upper=0,lower=0,digit=0,other=0;
    char ch;
    while((ch=fgetc(fp))!=EOF){                  
        if(ch=='\n')              lines++;
        else if(ch>='A'&&ch<='Z') upper++;
        else if(ch>='a'&&ch<='z') lower++;
        else if(ch>='0'&&ch<='9') digit++;
        else                      other++;
    }
    printf("行数=%d\n大写字母个数=%d\n小写字母个数=%d\n数字字符个数=%d\n其他字符的个数=%d\n",lines,upper,lower,digit,other);
}
int main()
{       
    FILE *fp;;                                   /*打开文件*/
    if((fp=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a.txt","r"))==NULL){
        printf("不能打开该文件\n");
        exit(0);
    }
    countFile(fp);                               /*调用统计函数*/
    if(fclose(fp)){                              /*关闭文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    return 0;
}