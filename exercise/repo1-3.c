/*程序功能：建立一个单向链表，头指针是list，链表中每个结点包含姓名、基本工资信息，编写del_list函数删除链表中等于某给定基本工资的所有结点。
要求在主函数中先建立单向链表（注：当输入基本工资为0时，表示输入结束。），再输入一个给定基本工资，
然后调用del_list函数删除链表中等于给定基本工资的所有结点，最后输出删除后的链表信息。*/
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
    struct staff *create_linked_list();     /*函数调用声明*/
    struct staff *del_list(struct staff *list);
    void print_linked_list(struct staff *list);

    struct staff *list=create_linked_list();   
    list=del_list(list);
    print_linked_list(list);
    return 0;     
}
/*函数功能：删除链表中等于某给定基本工资的所有结点*/
struct staff *del_list(struct staff *list)
{
    struct staff *p1,*p2;
    double DelWage;
    printf("请输入一个基本工资，以删除给定基本工资的所有职工的信息：");
    scanf("%lf",&DelWage);
    while(list->wage==DelWage) /*首结点的删除*/
  	{
  		list=list->next;
	}
    p1=list;
    while(p1->next!=NULL)              /*中间结点和尾结点的删除*/
    {
        if(p1->next->wage==DelWage)
        {
            p2=p1->next;
            p1->next=p2->next;
            free(p2);
        }
        else p1=p1->next;
    }
    return list;
}
void print_linked_list(struct staff *list)
{
    struct staff *p=list;
    printf("\n职工信息：\n姓名            基本工资\n");
    while(p!=NULL)
    {
        printf("%-16s%-16.2lf\n",p->name,p->wage);
        p=p->next;
    }
}
struct staff *create_linked_list()         
{
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
        if(p1->wage==0)break;          /*当输入基本工资为0时，表示输入结束*/
        if(i==1) list=p1;else p2->next=p1;  /*在表尾连入新节点*/
        p2=p1;                              /*p2指向新的表尾结点*/
    }
    return list;
}