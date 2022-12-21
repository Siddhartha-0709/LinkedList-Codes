#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create(struct node **head, int n)
{
    struct node *ptr, *prev;
    for (int i = 0; i < n; i++)
    {
        ptr = malloc(sizeof(struct node));
        printf("Enter Data? ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if (*head == NULL)
        {
            *head = ptr;
            prev = ptr;
        }
        else
        {
            prev->next = ptr;
            prev = ptr;
        }
    }
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
struct node *reverse(struct node **head)
{
    struct node *p = NULL, *q = NULL, *r = NULL;
    p = *head;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
    p = *head;
    return *head;
}

void merge(struct node *p, struct node **q)
{
    struct node *p_curr = p, *q_curr = *q;
    struct node *temp1, *temp2;

    while (p_curr != NULL && q_curr != NULL)
    {
        temp1 = p_curr->next;
        temp2 = q_curr->next;

        q_curr->next = temp1;
        p_curr->next = q_curr;

        p_curr = temp1;
        q_curr = temp2;
    }
    *q = q_curr;
}
void arrange(struct node **head, int n)
{
    struct node *ptr, *p, *temp1, *temp2, *ptr1, *ptr2;
    ptr = *head;
    for (int i = 1; i <= n / 2 - 1; i++, ptr = ptr->next)
        ;
    p = ptr->next;
    ptr->next = NULL;
    p = reverse(&p);
    ptr = *head;
    // display(ptr);
    // printf("\n");
    // display(p);

    *head = ptr;
    merge(ptr, &p);
}
int main()
{
    printf("How many nodes? ");
    int n;
    scanf("%d", &n);
    struct node *head;
    head = NULL;
    create(&head, n);
    arrange(&head, n);
    display(head);
    return 0;
}