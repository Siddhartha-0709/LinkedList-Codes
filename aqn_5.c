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
void display_n_node(struct node *head, int n)
{
    printf("\nEnter Value of N? ");
    int num;
    scanf("%d",&num);
    struct node *curr = malloc(sizeof(struct node));
    curr = head;
    if(num>n)
    {
        return;
    }
    for(int i=0;i<n-num;i++)
    {
        curr=curr->next;
    }
    printf("Data-%d",curr->data);
}
int main()
{
    struct node *head = NULL;
    printf("How many nodes? ");
    int n;
    scanf("%d", &n);
    create(&head, n);
    display(head);
    display_n_node(head,n);
    return 0;
}