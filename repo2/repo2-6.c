/*程序功能：从键盘输入若干个学生数据（包括学号、姓名和成绩）保存到二进制文件 a.dat（以负数成绩表示输入结束），然后再从该文件中读出并显示。*/
#include <stdio.h>
#include <stdlib.h>
typedef struct student{
    int num;
    char name[50];
    double score;
}STUDENT;
int main()
{
    FILE *fp;
    STUDENT s;
    int count,i;                                 /*打开文件*/
    if((fp=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a2.dat","wb+"))==NULL){     
        printf("不能打开该文件\n");
        exit(0);
    }
    printf("请输入学生学号、姓名、成绩（以负数成绩表示输入结束）：\n");
    for(count=0;;count++){                       /*写入学生数据*/
        scanf("%d%s%lf",&s.num,&s.name,&s.score);
        if(s.score<0) break;                     
        fwrite(&s,sizeof(s),1,fp);
    }
    rewind(fp);                                  /*指针返回文件首*/
    printf("学号      姓名      成绩\n");         /*读出学生数据*/
    for(i=1;i<=count;i++){
        fread(&s,sizeof(s),1,fp);
        printf("%-10d%-10s%-10.2lf\n",s.num,s.name,s.score);
    }
    if(fclose(fp)){                              /*关闭文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    return 0;
}