/*程序功能：输入若干个学生成绩（输入-1为结束标志），建立两个已按升序排序的单向链表，头指针分别为list1、list2，
把两个链表拼成一个升序排序的新链表，并输出新链表信息。要求自定义函数，实现将两个链表拼成一个链表，并返回拼组后的新链表。*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct student{
    char name[50];
    double score;
    struct student *next;
};
int main()
{
    struct student *create_linked_list();  /*函数调用声明*/
    void print_linked_list(struct student *list);
    struct student *merge_linked_list(struct student *list1,struct student *list2);
    
    struct student *list1,*list2,*list3;
    list1=create_linked_list();
    list1=sort_linked_list(list1);
    
    list2=create_linked_list();
    list2=sort_linked_list(list2);
    
    list3=merge_linked_list(list1,list2);
    list3=sort_linked_list(list3);
    print_linked_list(list3);
    return 0;
}
struct student *sort_linked_list(struct student *list)
{
  

}
struct student *merge_linked_list(struct student *list1,struct student *list2)
{
    struct student *p=list1;
    if(p->next==NULL) p->next=list2;
    else
    {   
        while(p->next!=NULL) p=p->next;        
        p->next=list2;
    }
    return list1;
}
void print_linked_list(struct student *list)
{
    struct student *p=list;
    printf("学生信息：\n姓名            成绩\n");
    while(p!=NULL)
    {
        printf("%-16s%-16.2lf\n",p->name,p->score);
        p=p->next;
    }
}
struct student *create_linked_list()         
{
    int i;
    struct student *list=NULL,*p1,*p2=NULL;/*list：头指针，p2：尾指针*/
    for(i=1;;i++)                          /*建立链表的结点*/
    {
        if((p1=(struct student *)malloc(sizeof(struct student)))==NULL){
            printf("不能成功分配储存块。");
            exit(0);
        }                      
        p1->next=NULL;                     /*令新节点的指针域为NULL*/      
        printf("请输入第%d位学生姓名、成绩：（当输入成绩为-1时，表示输入结束）\n",i);     
        scanf("%s%lf",&p1->name,&p1->score);
        if(p1->score==-1)break;            /*当输入成绩为-1时，表示输入结束*/
        if(i==1) list=p1;else p2->next=p1; /*在表尾连入新节点*/
        p2=p1;                             /*p2指向新的表尾结点*/
    }
    return list;
}





















