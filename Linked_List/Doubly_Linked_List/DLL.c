//  Doubly Linked List
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
void addFirst()
{
	node *newNode = createNode();
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		node *temp = head;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
void addLast()
{
	addNode();
}
int addAtPos(int pos)
{
	int count = countNode();
	node *newNode = createNode();
	if (pos <= 0 || pos >= count + 2)
	{
		printf("Invalid\n");
		return -1;
	}
	else if (pos == 1)
	{
		addFirst();
		return 0;
	}
	else
	{
		node *temp = head;
		while (pos - 2)
		{
			temp = temp->next;
			pos--;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
	}
}
int delFirst()
{
	int count = countNode();
	if (head = NULL)
	{
		printf("Nothing to Delete\n");
		return -1;
	}
	else if (count == 1)
	{
		free(head);
		head = NULL;
	}
	else
	{
		head = head->next;
		free(head->prev);
		head->prev = NULL;
	}
	return 0;
}
int delLast()
{
	int count = countNode();
	if (head == NULL)
	{
		printf("Nothing to Delete\n");
		return -1;
	}
	else if (count == 1)
	{
		free(head);
		head = NULL;
	}
	else
	{
		node *temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
	return 0;
}
int delAtPos(int pos)
{
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
int main()
{
	char choice;
	do
	{
		printf("===============Doubly Linked List===============\n");
		printf("1.ADD NODE\n2.PRINT NODE\n3.ADD AT FIRST NODE\n4.ADD AT LAST NODE\n5.ADD AT POSITION\n6.DELETE FIRST NODE\n7.DELETE LAST NODE\n8.DELETE AT POSITION\n9.REVERSE LINKED LIST\n");
		printf("================================================\n");
		int ch;
		printf("Enter Your Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			addNode();
			break;
		case 2:
			printLL();
			break;
		case 3:
			addFirst();
			break;
		case 4:
			addLast();
			break;
		case 5:
		{
			int pos;
			printf("Enter Position To Add Node : ");
			scanf("%d", &pos);
			printf("Position %d Selected\n", pos);
			addAtPos(pos);
			printf("At Position %d Node Successfully Added.\n", pos);
		}
		break;
		case 6:
			delFirst();
			break;
		case 7:
			delLast();
			break;
		case 8:
		{
			int pos;
			printf("Enter Position To Add Node : ");
			scanf("%d", &pos);
			delAtPos(pos);
			printf("At Position %d Node Successfully Deleted.\n", pos);
			break;
		}
		case 9:
			reverseDLL();
			break;
		default:
			printf("Invalid Input\n");
		}
		printf("Do you want to continue ?(Y/N)\n");
		getchar();
		scanf("%c", &choice);
	} while (choice == 'y' || choice == 'Y');
}