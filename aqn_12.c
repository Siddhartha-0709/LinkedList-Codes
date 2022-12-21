#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void create(struct node** H, int x)
{
    struct node* ptr, * cur;

    for(int i = 0 ; i < x ; i++)
    {
        cur = malloc(sizeof(struct node));
        printf("Enter Data? ");
        scanf("%d",&cur->data);

        cur->next = NULL;

        if(*H == NULL)
            *H = ptr = cur;
        else
        {
            ptr->next = cur;
            ptr = cur;
        }
    }
}
void arrange(struct node** H1, struct node** H2)
{
    struct node* first = *H1, * p = *H1;
    struct node* second = *H2, * q = *H2;

    while(first->next != NULL)
    {
        first = first->next;
        second = second->next;
        q->next = first;
        p->next = q;
        q = second;
        p = first;
    }
    p->next = q;
}
void display(struct node* H)
{
    struct node* ptr = H;

    while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }   
}

int main()
{
    int n;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    create(&head1,n);

    printf("Enter number of nodes: ");
    scanf("%d",&n);
    create(&head2,n);

    printf("\nThe first linked list is: ");
    display(head1);
    printf("\nThe second linked list is: ");
    display(head2);

    arrange(&head1,&head2);
    display(head1);
    printf("\n");
    
    return 0;
}