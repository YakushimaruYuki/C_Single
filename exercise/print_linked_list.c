void print_linked_list (struct student *head)
{
    struct student *p=head;

    printf("学生成绩表\n");
    printf("=============\n");
    pritnf("%-5s%-5s\n","学号 ","成绩 ");
    while(p!=NULL){
        printf("%-5d  %-5d\n",p->num,p->score);
        p=p->next;
    }
}