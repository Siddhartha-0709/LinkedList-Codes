#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void insert(struct node **head, int v)
{
    struct node *ptr;
    struct node *curr = malloc(sizeof(struct node));
    curr->data = v;
    curr->prev = NULL;
    curr->next = NULL;
    if (*head == NULL)
    {
        *head = curr;
    }
    else
    {
        ptr = *head;
        curr->next = ptr;
        ptr->prev = curr;
        *head = curr;
    }
}
void delete (struct node **head, int postn)
{
    struct node *curr = *head;
    if (postn == 0)
    {
        if (curr->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            *head = curr->next;
        }
    }
    else
    {
        for (int i = 0; i < postn && curr!=NULL; i++)
        {
            curr = curr->next;
        }
        printf("Deleting Value- %d\n", curr->data);
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    free(curr);

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
int main()
{
    int cont;
    struct node *head=NULL;
    printf("Double Linked List\n");
    do
    {
        printf("Enter Choice:\n1-Insert\n2-Display\n3-Delete\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("How Many Nodes?\n");
            int n;
            scanf("%d", &n);
            while(n!=0)
            {
                printf("Enter Value? ");
                int v;
                scanf("%d",&v);
                insert(&head,v);
                n--;
            }
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter Position for Deletion? \n");
            int pos;
            scanf("%d", &pos);
            delete (&head, pos);
            break;
        default:
            break;
        }
        printf("\nDo you want to continue?\nYES-1 | NO-0\n");
        scanf("%d", &cont);
    }while (cont != 0);
    return 0;
}