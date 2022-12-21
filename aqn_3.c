#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void create(struct node **head, int node)
{
    struct node *curr, *pre = NULL;
    if (node == 0)
    {
        curr = malloc(sizeof(struct node));
        printf("Enter data? ");
        scanf("%d", &curr->data);
        curr->next = curr->prev = NULL;
    }
    else
    {
        for (int i = 0; i < node; i++)
        {
            curr = malloc(sizeof(struct node));
            printf("Enter data? ");
            scanf("%d", &curr->data);
            curr->next = NULL;
            if (i == 0)
            {
                curr->next = curr->prev = NULL;
                pre = curr;
                *head = curr;
            }
            else
            {
                pre->next = curr;
                curr->prev = pre;
                pre = curr;
            }
        }
    }
}
void display(struct node *head)
{
    struct node *curr = malloc(sizeof(struct node));
    curr = head;
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
}
void node_reverse(struct node **head)
{
    struct node *curr, *ptr, *temp=NULL;
    curr = *head;
    while(curr!=NULL)
    {
        ptr=curr;
        curr=curr->next;
    }
    curr=ptr;
    *head=curr;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->next;
    }
    
}
int main()
{
    int n;
    struct node *head = NULL;
    printf("Enter Number of Nodes? ");
    scanf("%d", &n);
    create(&head, n);
    display(head);
    node_reverse(&head);
    printf("\nReversed Data after reversing nodes-\n");
    display(head);
    return 0;
}