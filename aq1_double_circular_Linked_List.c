#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
void insert(struct node **head, int n)
{
    struct node *curr, *prev;
    for (int i = 0; i < n; i++)
    {
        curr = malloc(sizeof(struct node));
        printf("Enter Data? ");
        scanf("%d", &curr->data);
        curr->next = NULL;
        curr->prev = NULL;
        if (i == 0)
        {
            *head = curr;
            prev = curr;
        }
        else
        {
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }
    }
    curr->next = *head;
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
            *head=curr->next;
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
        }
    }
    else
    {
        for (int i = 0; i < postn && curr != NULL; i++)
        {
            curr = curr->next;
        }
        printf("Deleting Value- %d\n", curr->data);

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    free(curr);

}
void display(struct node *head)
{
    struct node *curr;
    curr = head;
    do
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    } while (curr != head);
}
int main()
{
    int cont;
    struct node *head = NULL;
    printf("How many nodes? ");
    int n;
    scanf("%d", &n);
    insert(&head, n);
    display(head);
    printf("Enter Node to Delete? ");
    int pos;
    scanf("%d", &pos);
    delete (&head, pos);
    display(head);
    return 0;
}