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
void reverse(struct node *head, int m, int n)
{
    // base case
    if (m > n)
    {
        return;
    }

    struct node *prev = NULL; // the previous pointer
    struct node *curr = head; // the main pointer

    // 1. Skip the first `m` nodes
    for (int i = 1; curr != NULL && i < m; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // `prev` now points to (m-1)'th node
    // `curr` now points to m'th node

    struct node *start = curr;
    struct node *end = NULL;

    // 2. Traverse and reverse the sublist from position `m` to `n`
    for (int i = 1; curr != NULL && i <= n - m + 1; i++)
    {
        // Take note of the next node
        struct node *next = curr->next;

        // move the current node onto the `end`
        curr->next = end;
        end = curr;

        // move to the next node
        curr = next;
    }

    /*
        `start` points to the m'th node
        `end` now points to the n'th node
        `curr` now points to the (n+1)'th node
    */

    // 3. Fix the pointers and return the head node

    if (start)
    {
        start->next = curr;
        if (prev != NULL)
        {
            prev->next = end;
        }
        // when m = 1, `prev` is nullptr
        else
        {
            // fix the head pointer to point to the new front
            head = end;
        }
    }
}
int main()
{
    struct node *head = NULL;
    printf("How many nodes? ");
    int n;
    scanf("%d", &n);
    create(&head, n);
    // printf("\n");
    display(head);
    printf("Enter Value of M and N? ");
    int m,t;
    scanf("%d%d",&m,&t);
    reverse(head,m,t);
    display(head);

    return 0;
}