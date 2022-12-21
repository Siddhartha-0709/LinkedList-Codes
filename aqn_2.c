#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node **head, int node)
{
    struct node *curr,*ptr=NULL;
    for(int i=0;i<node;i++)
    {
        curr=malloc(sizeof(struct node));
        if(i==0)*head=curr;
        curr->next=NULL;
        printf("Enter Data? ");
        scanf("%d",&curr->data);
        if(i!=0)
        {
            ptr->next=curr;
        }
        ptr=curr;
    }
}
void display(struct node *head)
{
    struct node *p=head,*q=NULL,*r= NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
    while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
}
int main()
{
   struct node *head= NULL; 
   create(&head,5);
   display(head);
   return 0;
}