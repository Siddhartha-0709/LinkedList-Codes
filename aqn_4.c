#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void insert(struct Node ** head, int v)
{
	struct Node*  curr =malloc(sizeof(struct Node));
	curr->data = v;
	curr->next = (*head);
	(*head) =  curr;
}

void display(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void swapPairs(struct Node **head)
{
	while(*head && (*head)->next)
	{
		struct Node *ptr1 = *head;
		struct Node *ptr2 = ptr1->next->next;
		*head = ptr1->next;
		ptr1->next->next = ptr1;
		ptr1->next = ptr2;
		head = &ptr1->next;
	}
}

int main()
{
	struct Node *head = NULL;
    printf("How many nodes? ");
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int v;
        printf("Enter Value? ");
        scanf("%d",&v);
        insert(&head,v);
        n--;
    }
	printf("Actual List:\n");
	display(head);
	swapPairs(&head);
	printf("ModifiedLinked List:\n");
	display(head);

	return 0;
}
