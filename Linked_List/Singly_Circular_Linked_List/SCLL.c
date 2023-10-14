#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* head = NULL;

node *createNode(){
	node *newNode = (node *)malloc(sizeof(node));
	printf("Enter Data : ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	return newNode;
}

void addNode(){
	node *newNode = createNode();
	if (head == NULL)
	{
		head = newNode;
        newNode -> next = head;
	}
	else
	{
		node *temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
        newNode -> next = head;
	}
}

int printLL(){
    node* temp = head;
    if(head == NULL){
        printf("Nothing to Print\n");
        return -1;
    }else{
        while(temp->next!=head){
            printf("|%d|<->",temp->data);
            temp = temp -> next;
        }
        printf("|%d|\n",temp->data);
        return 0;
    }
}

int countNode(){
	int count = 1;
	node* temp = head;
	while(temp->next!=head){
		count++;
		temp = temp -> next;
	}
	return count;
}

int addFirst(){
	node* newNode = createNode();
	if(head!=NULL){
		addNode();
	}else{
		node* temp = head;
		while(temp->next!= head){
			temp = temp -> next;
		}
		temp -> next = newNode;
		newNode->next = head;
		head = newNode;
	}
}

int main()
{
	char choice;
	do
	{
		printf("========= Singly Circular Linked List ==========\n");
		printf("1.ADD NODE\n2.PRINT NODE\n3.ADD AT FIRST NODE\n4.ADD AT LAST NODE\n5.ADD AT POSITION\n6AS.DELETE FIRST NODE\n7.DELETE LAST NODE\n8.DELETE AT POSITION\n9.REVERSE LINKED LIST\n");
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
		// 	break;
		// case 4:
		// 	addLast();
		// 	break;
		// case 5:
		// {
		// 	int pos;
		// 	printf("Enter Position To Add Node : ");
		// 	scanf("%d", &pos);
		// 	printf("Position %d Selected\n", pos);
		// 	addAtPos(pos);
		// 	printf("At Position %d Node Successfully Added.\n", pos);
		// }
		// break;
		// case 6:
		// 	delFirst();
		// 	break;
		// case 7:
		// 	delLast();
		// 	break;
		// case 8:
		// {
		// 	int pos;
		// 	printf("Enter Position To Add Node : ");
		// 	scanf("%d", &pos);
		// 	delAtPos(pos);
		// 	printf("At Position %d Node Successfully Deleted.\n", pos);
		// 	break;
		// }
		// case 9:
		// 	reverseDLL();
		// 	break;
		default:
			printf("Invalid Input\n");
		}
		printf("Do you want to continue ?(Y/N)\n");
		getchar();
		scanf("%c", &choice);
	} while (choice == 'y' || choice == 'Y');
	int count = countNode();
	printf("%d\n",count);
}
