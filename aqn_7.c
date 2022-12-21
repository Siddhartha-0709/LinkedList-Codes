#include <stdlib.h>
#include <stdio.h>
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
int reverse_check(struct node *h1, struct node *h2)
{
    struct node *ptr, *ptr2;
    ptr = h1;
    ptr2 = h2;
    while (ptr != NULL)
    {
        if (ptr->data != ptr2->data)
        {
            return 1;
        }
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }
    return 0;
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
    struct node *head, *head2;
    head2 = NULL;
    head = NULL;
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);
    create(&head, n);
    struct node *ptr;
    ptr = head;
    while (n != 0)
    {
        insert(&head2, ptr->data);
        ptr=ptr->next;
        n--;
    }
    // printf("\nList-1 \n");
    // display(head);
    // printf("\nList-2 \n");
    // display(head2);
    int k = reverse_check(head, head2);
    if (k == 1)
    {
        printf("\nNOT PALINDROME\n");
    }
    else
    {
        printf("\nPALINDROME\n");
    }
    return 0;
}