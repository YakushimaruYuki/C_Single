/*程序功能：已知一个数据文件a.txt中保存了若干个学生的计算机等级考试成绩，包括学号、姓名和成绩。
请编程读出显示文件内容并分类统计各等级人数，最后显示统计结果。成绩等级规则：大于等于90-A，大于等于80-B，大于等于70-C，大于等于60-D，60以下-E。*/
#include <stdio.h>
#include <stdlib.h>
typedef struct student{
    int num;
    char name[50];
    double score;
}STUDENT;
int main()
{
    int A=0,B=0,C=0,D=0,E=0;
    STUDENT s;
    FILE *fp;                                    /*打开文件*/
    if((fp=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a.txt","r"))==NULL){
        printf("不能打开该文件\n");
        exit(0);
    }                                            /*读取并统计各等级人数*/ 
    while(fscanf(fp,"%d%s%lf",&s.num,&s.name,&s.score)!=EOF){      
        if(s.score>=90)      A++;
        else if(s.score>=80) B++;
        else if(s.score>=70) C++;
        else if(s.score>=60) D++;
        else if(s.score<60)  E++;
    }
    if(fclose(fp)){                              /*关闭文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    printf("A=%d人,B=%d人,C=%d人,D=%d人,E=%d人\n",A,B,C,D,E);
    return 0;
}