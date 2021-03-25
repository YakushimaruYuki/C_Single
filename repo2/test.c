/*read only*/
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
    int i;                                                                      
    if((fp=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a1.dat","rb"))==NULL){     /*打开文件*/
        printf("不能打开该文件\n");
        exit(0);
    }
    
    printf("学号      姓名      成绩\n");         /*输出学生数据*/
    for(i=1;fread(&s,sizeof(s),1,fp);i++){     
        
        printf("%-10d%-10s%-10.2lf\n",s.num,s.name,s.score);
    }

    
    if(fclose(fp)){                              /*关闭文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    return 0;
}

