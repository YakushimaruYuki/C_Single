/*程序功能：两个非空二进制文件 a1.dat 和 a2.dat，分别保存若干学生数据（包括学号、姓名和成绩），且按成绩升序排列。编写程序，
把 a1.dat 和 a2.dat 两个文件归并到 a3.dat 文件，使得 a3.dat 文件中的学生数据也按成绩升序排列。要求如下：
① 定义 mergeFile()函数：将两个二进制文件归并成一个按成绩升序排列的新文件。      ② 定义 main()函数：先打开二进制文件 a1.dat、a2.dat、a3.dat，
再调用 mergeFile()函数将 a1.dat、a2.dat 两个文件归并到按成绩升序排列的 a3.dat 文件，最后输出 a3.dat 文件内容。 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct student{
    int num;
    char name[50];
    double score;
}STUDENT;
int mergeFile(FILE *fp1,FILE *fp2,FILE *fp3)     
/*函数功能：将第1、第2文件归并到按成绩升序排列的第3文件*/
{ 
    STUDENT s[SIZE],temp;
    int i=0,j,count=0;
    while(fread(&s[i],sizeof(STUDENT),1,fp1)){   /*把a1.dat读取到临时的数组*/
        i++;
    }
    while(fread(&s[i],sizeof(STUDENT),1,fp2)){   /*把a2.dat读取到临时的数组*/
        i++;
    }
    count=i;  
    for(i=0;i<count-1;i++){                      /*冒泡升序排序数组*/
        for(j=0;j<count-i-1;j++){
            if(s[j].score>s[j+1].score){
                temp=s[j];s[j]=s[j+1];s[j+1]=temp;
            }
        }
    }
    for(i=0;i<count;i++){                        /*把数组写入a3.dat*/
        fwrite(&s[i],sizeof(STUDENT),1,fp3);
    }
    rewind(fp3);
    return count;                                /*返回a3.dat的学生人数*/
}
int main()
{
    int i,count;
    STUDENT s;
    FILE *fp1,*fp2,*fp3;                         /*打开3个文件*/
    if((fp1=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a1.dat","rb"))==NULL){     
        printf("不能打开该文件\n");
        exit(0);
    }
    if((fp2=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a2.dat","rb"))==NULL){     
        printf("不能打开该文件\n");
        exit(0);
    }
    if((fp3=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a3.dat","wb+"))==NULL){     
        printf("不能打开该文件\n");
        exit(0);
    }

    count=mergeFile(fp1,fp2,fp3);                /*调用合并文件函数*/

    printf("学号      姓名      成绩\n");         /*读出学生数据*/
    for(i=1;i<=count;i++){
        fread(&s,sizeof(s),1,fp3);
        printf("%-10d%-10s%-10.2lf\n",s.num,s.name,s.score);
    }
    if(fclose(fp1)){                             /*关闭3个文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    if(fclose(fp2)){                              
        printf("不能正常关闭文件\n");
        exit(0);
    }
    if(fclose(fp3)){                              
        printf("不能正常关闭文件\n");
        exit(0);
    }
    return 0;
}