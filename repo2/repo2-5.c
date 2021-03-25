/*程序功能：从键盘输入10个英文单词到二维字符数组a并保存到文本文件a.txt中（单词间以空格分隔），然后再从该文件中读出所有单词并显示到屏幕。*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    int i;
    char a[10][46],word[46];
    printf("请输入10个英文单词：\n");        
    for(i=0;i<10;i++){                      /*输入10个英文单词到二维数组a*/
        scanf("%s",&a[i]);
    }                                       /*打开文件*/
    if((fp=fopen("C:\\Codefield\\CODE_C\\C_Single\\repo2\\a5.txt","w+"))==NULL){
        printf("不能打开该文件\n");
        exit(0);
    }
    for(i=0;i<10;i++){                      /*把数组写入a.txt*/
        fprintf(fp,"%s ",a[i]);
    }                                           
    rewind(fp);                             /*指针返回文件首*/
    for(i=0;i<10;i++){                      /*读出10个英文单词*/
        fscanf(fp,"%s",word);
        printf("%s ",word);
    }
    if(fclose(fp)){                         /*关闭文件*/
        printf("不能正常关闭文件\n");
        exit(0);
    }
    return 0;
}

    