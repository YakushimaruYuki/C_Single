struct student *delete_node(struct student *head,int num)
{
    struct student *p1=head,*p2=head;

    while((p1->num!=num))&&(p1->next!=NULL){
        p2=p1;p1=p1->next;
    }

    if(p1->num==num){
        if(head==p1) head=p1->next;
        else p2->next=p1->next;
        free(p1);
    }
    else printf("无删除结点\n");

    return head;

}