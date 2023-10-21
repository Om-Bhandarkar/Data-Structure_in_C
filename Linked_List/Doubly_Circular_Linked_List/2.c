#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
}node;

node * head = NULL;
node* createNode() {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->prev = NULL;
    printf("Enter the data : ");
    scanf("%d",&newNode->data);
    newNode-> next = NULL;
    return newNode;
}

void addNode(){
    node* newNode = createNode();
    if(head == NULL){
        head =  newNode;
        head -> prev = head;
        head -> next = head;
    }else{
        node* temp = head;
        while(temp->next != head){
            temp = temp -> next;
        }
        temp -> prev = newNode;
        temp -> next = newNode;
        newNode -> prev = head;
        newNode -> next = head;
    }
}
int printLL(){
    node* temp = head;
    if(head == NULL){
        printf("Nothing to print\n");
        return -1;
    }else{
        while(temp -> next != head){
            printf("|%d|->",temp -> data);
            temp = temp -> next;
        }
        printf("|%d|\n",temp->data);
        return 0;
    }
}

int delLast(){
        node* temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> prev -> next = head;
        head -> prev = temp -> prev;
        free(temp);
        return 0;
}

void main(){
    addNode();
    addNode();
    addNode();
    addNode();
    printLL();
    delLast();
    printLL();
}