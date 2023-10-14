#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
} node;
node *head = NULL;
node *createNode()
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->prev = NULL;
	printf("Enter Data : ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}
void addNode()
{
	node *newNode = createNode();
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}
int countNode()
{
	int count = 0;
	node *temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
void printLL()
{
	node *temp = head;
	while (temp->next != NULL)
	{
		printf("|%d|<->", temp->data);
		temp = temp->next;
	}
	printf("|%d|\n", temp->data);
}
int reverseDLL()
{
	int count = countNode();
	if (count == 0)
	{
		printf("Empty Linked List\n");
		return -1;
	}
	int cmt = count / 2;
	node *temp1 = head;
	node *temp2 = head;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	while (cmt)
	{
		int temp = temp1->data;
		temp1->data = temp2->data;
		temp2->data = temp;
		temp1 = temp1->next;
		temp2 = temp2->prev;
		cmt--;
	}
	return 0;
}
void main()
{
	int node;
	printf("Enter how many node you have : \n");
	scanf("%d",&node);
	for (int i = 1; i <= node; i++)
	{
		addNode();
	}
	printLL();
	reverseDLL();
	printLL();
}