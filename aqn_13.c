#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create(struct node **head, int node)
{
    struct node *curr, *ptr = NULL;
    for (int i = 0; i < node; i++)
    {
        curr = malloc(sizeof(struct node));
        if (i == 0)
            *head = curr;
        curr->next = NULL;
        printf("Enter Data? ");
        scanf("%d", &curr->data);
        if (i != 0)
        {
            ptr->next = curr;
        }
        ptr = curr;
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
void arrange(struct node *head, int n)
{
    int arr[n];
    int i=0;
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            arr[i++]=ptr->data;
        }
        ptr=ptr->next;
    }
    
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data%2!=0)
        {
            arr[i++]=ptr->data;
        }
        ptr=ptr->next;
    }

    ptr=head;
    for(int j=0;j<n;j++)
    {
        ptr->data=arr[j];
        ptr=ptr->next;
    }
}
int main()
{
    struct node *head = NULL;
    printf("How many nodes? ");
    int n;
    scanf("%d", &n);
    create(&head, n);
    //display(head);
    //printf("\n");
    arrange(head,n);
    display(head);
    return 0;
}