#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void create(int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data? ");
    scanf("%d",&head->data);
    head->next = NULL;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter Data? ");
        scanf("%d",&t->data);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
int main()
{

    printf("How many nodes? ");
    int n;
    scanf("%d",&n);
    create(n);
    RemoveDuplicate(head);
    Display(head);

    return 0;
}