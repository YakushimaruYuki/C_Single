/*程序功能：输入若干个学生成绩（输入-1为结束标志），建立两个已按升序排序的单向链表，头指针分别为list1、list2，
把两个链表拼成一个升序排序的新链表，并输出新链表信息。要求自定义函数，实现将两个链表拼成一个链表，并返回拼组后的新链表。*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
struct student{
    char name[50];
    double score;
    struct student *next;
};
int main()
{
    struct student *create_linked_list();   /*函数调用声明*/
    void print_linked_list(struct student *list);
    struct student *merge_linked_list(struct student *list1,struct student *list2);
    struct student *sort_linked_list(struct student *list);
    
    struct student *list1,*list2,*list3;
    printf("第一链表：\n");  
    list1=create_linked_list();             /*建立第一链表，并升序排序*/
    list1=sort_linked_list(list1);  
    
    printf("\n第二链表：\n"); 
    list2=create_linked_list();             /*建立第二链表，并升序排序*/
    list2=sort_linked_list(list2);          
    
    list3=merge_linked_list(list1,list2);   /*合并两链表，并升序排序*/
    list3=sort_linked_list(list3);
    
    print_linked_list(list3);               /*输出合并后的链表*/
    return 0;
}
/*函数功能：升序排序链表（用选择排序法）*/
struct student *sort_linked_list(struct student *list)
{
    struct student *p1,*p2=list;  /*p1:前指针，p2：后指针*/    
    double min,TempScore;         /*TempScore和TempName：用于交换的临时变量*/    
    char TempName[50];
    while(p2->next!=NULL)
    {
        p1=p2->next;              /*令p1在p2的下一个结点*/
        min=p2->score;            /*先假定p2->score最小*/
        while(p1!=NULL)           /*p1向后遍历链表，找到本轮的最小值*/
        {
            if(p1->score<min) min=p1->score;
            p1=p1->next;
        }
        p1=p2->next;                   
        if(min<p2->score)         /*若本轮的最小值比p2->score更小，交换两者的数据域*/
        {
            while(p1->score!=min) p1=p1->next;
            TempScore=p2->score;p2->score=p1->score;p1->score=TempScore;
            strcpy(TempName,p2->name);
            strcpy(p2->name,p1->name);
            strcpy(p1->name,TempName);
        }
        p2=p2->next;              /*p2向下一个结点移动*/
    }
    return list;
}
/*函数功能：首尾相接地合并两个链表*/
struct student *merge_linked_list(struct student *list1,struct student *list2)
{
    struct student *p=list1;
    if(p->next==NULL)                  /*若list1只有一个结点，令p->list2*/                       
    { 
        p->next=list2;return list1;
    }
    while(p->next!=NULL) p=p->next;    /*若list1有多个结点，令list1最后的节点->list2*/
    p->next=list2;
    return list1;
}
void print_linked_list(struct student *list)
{
    struct student *p=list;
    printf("\n学生信息：\n姓名            成绩\n");
    while(p!=NULL)
    {
        printf("%-16s%-16.2lf\n",p->name,p->score);
        p=p->next;
    }
}
struct student *create_linked_list()         
{
    int i;
    struct student *list=NULL,*p1,*p2=NULL; /*list：头指针，p2：尾指针*/
    for(i=1;;i++)                           /*建立链表的结点*/
    {
        if((p1=(struct student *)malloc(sizeof(struct student)))==NULL){
            printf("不能成功分配储存块。");
            exit(0);
        }                      
        p1->next=NULL;                      /*令新节点的指针域为NULL*/      
        printf("请输入第%d位学生姓名、成绩：（当输入成绩为-1时，表示当前链表输入结束）\n",i);     
        scanf("%s%lf",&p1->name,&p1->score);
        if(p1->score==-1)break;             /*当输入成绩为-1时，表示输入结束*/
        if(i==1) list=p1;else p2->next=p1;  /*在表尾连入新节点*/
        p2=p1;                              /*p2指向新的表尾结点*/
    }
    return list;
}





















