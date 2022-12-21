#include<stdio.h>
#include<stdlib.h>

struct node
{
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
    curr->next=*head;
}

void display(struct node *head)
{
    struct node *ptr= head;
    do
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
}

void delete(struct node **head, int pos)
{
    struct node *ptr=*head, *prev;
    if(pos==0)
    {
        ptr=*head;
        do
        {
            prev= ptr;
            ptr=ptr->next;
        }while(ptr!=*head);

        prev->next=ptr->next;
        *head=ptr->next;
        printf("\nDeleting Value-%d\n",ptr->data);
        free(ptr);
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->next;
        }
        struct node *temp= ptr;
        ptr=ptr->next;
        printf("\nDeleting Value-%d\n",ptr->data);
        temp->next=ptr->next;
        free(ptr);
    }
}

int main()
{
   struct node *head;
   head=NULL;
   printf("How many nodes? ");
   int n;
   scanf("%d",&n);
   create(&head,n);
   display(head);
   printf("\nWhich Position to Delete? ");
   int pos;
   scanf("%d",&pos);
   delete(&head,pos);
   display(head);

   return 0;
}