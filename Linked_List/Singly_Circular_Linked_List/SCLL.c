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

void addLast(){
	addNode();	
}
