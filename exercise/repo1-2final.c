/*程序功能：建立一个单向链表，头指针是list，链表中每个结点包含姓名、基本工资信息，编写count_list函数统计链表中超过平均基本工资的人数。
要求在主函数中建立单向链表（注：当输入基本工资为0时，表示输入结束。），然后调用count_list函数统计链表中超过平均基本工资的人数，
最后输出统计结果和平均基本工资。*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct staff{
    char name[50];
    double wage;
    struct staff *next;
};
int main()
{
       
    void count_list(struct staff *list);    /*函数调用声明*/
   
    int i;
    struct staff *list=NULL,*p1,*p2=NULL;   /*list：头指针，p2：尾指针*/
    for(i=1;;i++)                           /*建立链表的结点*/
    {
        if((p1=(struct staff *)malloc(sizeof(struct staff)))==NULL){
            printf("不能成功分配储存块。");
            exit(0);
        }                      
        p1->next=NULL;                      /*令新节点的指针域为NULL*/      
        printf("请输入第%d位员工姓名、基本工资：（当输入基本工资为0时，表示输入结束）\n",i);     
        scanf("%s%lf",&p1->name,&p1->wage);
        if(p1->wage==0)break;               /*当输入基本工资为0时，表示输入结束*/
        if(i==1) list=p1;else p2->next=p1;  /*在表尾连入新节点*/
        p2=p1;                              /*p2指向新的表尾结点*/
    }
   
    count_list(list);                       
    return 0; 
}
/*函数功能：统计链表中超过平均基本工资的人数，并输出结果*/
void count_list(struct staff *list)
{
    unsigned int list_length(struct staff *list);/*函数调用声明*/
    struct staff *p=list;
    double avg,sum=0;
    int count=0;
    while(p!=NULL)                               /*指针p遍历链表，累计工资的总和*/
    {        
        sum+=p->wage;
        p=p->next;
    }
    avg=sum/list_length(list);                   /*计算平均基本工资*/
    p=list;
    while(p!=NULL)                               /*统计链表中超过平均基本工资的人数*/
    {
        if(p->wage>avg) count++;
        p=p->next;
    }
    printf("\n平均基本工资为%.2lf，超过平均基本工资的人数为%d。\n",avg,count);
}
unsigned int list_length(struct staff *list)
{
    struct staff *p=list;
    unsigned int length=0;
    while(p!=NULL)
    {
        length++;
        p=p->next;
    }
    return length;
}

