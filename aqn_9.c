#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void create(struct node **head, int n)
{
    struct node *curr, *prev = NULL;

    for (int i = 0; i < n; i++)
    {
        if (*head == NULL)
        {
            curr = malloc(sizeof(struct node));
            curr->next = NULL;
            curr->prev = NULL;
            printf("Enter Data? ");
            scanf("%d", &curr->data);
            prev = curr;
            *head = curr;
        }
        else
        {
            curr = malloc(sizeof(struct node));
            curr->next = NULL;
            curr->prev = NULL;
            printf("Enter Data? ");
            scanf("%d", &curr->data);
            curr->prev = prev;
            prev->next = curr;
            prev = curr;
        }
    }
}
void display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void rotate(struct node *head,int m, int n)
{
    struct node *ptr= head;
    for(int i=0;i<m;i++)
    {
        ptr=ptr->next;
    }
    //printf("data-%d",ptr->data);

    struct node *ptr2= head;
    for(int i=0;i<n;i++)
    {
        ptr2=ptr2->next;
    }
    //printf("data-%d\n",ptr2->data);

    ptr->prev->next=ptr2;
    ptr2->prev->next=ptr2->next;
    ptr2->prev=ptr->prev;
    ptr2->next=ptr;
    ptr = head;
}
int main()
{
    struct node *head;
    head = NULL;
    printf("How many nodes? ");
    int n;
    scanf("%d", &n);
    create(&head, n);
    display(head);
    printf("\nEnter M and N Value? ");
    int m, no;
    scanf("%d%d",&m,&no);
    printf("\nEnter Shift Value? ");
    int sh;
    scanf("%d",&sh);
    while(sh!=0)
    {
        rotate(head,m,no);
        sh--;
    }
    printf("\n");
    display(head);
    return 0;
}
