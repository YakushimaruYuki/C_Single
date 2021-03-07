/*程序功能：建立一个单向链表，头指针是list，链表中每个结点包含姓名、基本工资信息，编写max_list函数查找链表中最高基本工资的职工信息。
要求在主函数中建立单向链表（注：当输入基本工资为0时，表示输入结束。），然后调用max_list函数查找链表中最高基本工资的职工信息，最后输出查找结果。*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct staff{
    char name[50];
    double BasicWage;
    struct staff *next;
};
int main()
{
   struct staff *create_linked_list();     /*函数调用声明*/
   void max_list(struct staff *list);
   
   max_list(create_linked_list());        
   return 0;
}
/*函数功能：查找链表中最高基本工资的职工信息，输出查找结果*/
void max_list(struct staff *list)        
{ 
    struct staff *p=list;
    double max=p->BasicWage;
    while(p!=NULL)                         /*查找最高基本工资*/
    {
        if(max<p->BasicWage) max=p->BasicWage;
        p=p->next;
    }
    p=list;
    printf("最高基本工资的职工信息：\n姓名            基本工资\n");
    while(p!=NULL)                         /*输出最高工资的职工*/
    {
        if(p->BasicWage==max) printf("%-16s%-16.2lf\n",p->name,p->BasicWage);
        p=p->next;
    }
}
struct staff *create_linked_list()         
{
    int i;
    struct staff *list=NULL,*p1,*p2=NULL;  /*list：头指针，p2：尾指针*/
    for(i=1;;i++)                          /*建立链表的结点*/
    {
        if((p1=(struct staff *)malloc(sizeof(struct staff)))==NULL){
            printf("不能成功分配储存块。");
            exit(0);
        }                      
        p1->next=NULL;                     /*令新节点的指针域为NULL*/      
        printf("请输入第%d位员工姓名、基本工资：（当输入基本工资为0时，表示输入结束）\n",i);     
        scanf("%s%lf",&p1->name,&p1->BasicWage);
        if(p1->BasicWage==0)break;         /*当输入基本工资为0时，表示输入结束*/
        if(i==1) list=p1;else p2->next=p1; /*在表尾连入新节点*/
        p2=p1;                             /*p2指向新的表尾结点*/
    }
    return list;
}



