#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head, int v)
{
    struct node *curr = malloc(sizeof(struct node));
    curr->data = v;
    curr->next = NULL;
    if (*head == NULL)
    {
        *head = curr;
    }
    else
    {
        curr->next = *head;
        *head = curr;
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
int delete (struct node **head)
{
    struct node *ptr, *prev;
    ptr=*head;
    while(ptr!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        printf("\nDeleting Node with Value- %d\n",prev->data);
        free(prev);
    }
    *head=ptr;
    free(ptr);
    head=NULL;
    return 0;
}
int main()
{
    int cont;
    struct node *head = NULL;
    printf("Single Linked List\n");
    printf("How Many Nodes?\n");
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        printf("Enter Value? ");
        int v;
        scanf("%d", &v);
        insert(&head, v);
        n--;
    }
    printf("Displaying List\n");
    display(head);
    printf("\nDeleting List");
    delete(&head);
    return 0;
}