#include<stdio.h>
#include<stdlib.h>
 struct Node{
    int data;
    struct Node *next;
};

void main(){
    struct Node *head = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));    
    newNode -> data = 10;
    newNode -> next = NULL;
    head = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));    
    newNode -> data = 20;
    newNode -> next = NULL;
    head -> next = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));    
    newNode -> data = 30;
    newNode -> next = NULL;
    head -> next -> next = newNode;

    struct Node *temp = head;
    printf("Singly Linked List : ");
    while(temp -> next != NULL){
        printf("|%d|->",temp->data);
        temp = temp -> next;
    }
        printf("|%d|",temp->data);
    printf("\n");

}