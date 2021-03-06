struct student *insert_node (struct student *head, struct student *stud)
{
    struct student *p0,*p1,*p2;
    p1=head;p0=stud;

    if(head==NULL){
        head=p0;p0->next=NULL;
    }
    else
    {
        while ((p0->num>p1->num))&&(p1->next!=NULL))
        {
            p2=p1;p1=p1->next;
        }
        if(p0->num>p1->num){
            p1->next=p0;p0->next=NULL;
        }
        else if(head==p1){
            p0->next=head;head=p0;
        }
        else{
            p2->next=p0;p0->next=p1;
        }
    }
    return head;
}
