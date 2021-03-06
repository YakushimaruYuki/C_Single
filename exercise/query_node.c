struct student *query_node(struct student *head,int num)
{
    struct student *p=head;

    while((p->num!=num))&&(p->next!=NULL)) p=p->next;
    if(p->num!=num) p=NULL;
    return p;
}