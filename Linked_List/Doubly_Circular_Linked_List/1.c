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
void addFirst(){
    node * newNode = createNode();
    if(head == NULL){
        head = newNode;
        head -> prev = head;
        head -> next = head;
    }else{
        node* temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        newNode -> prev = temp;
        temp -> next = newNode;
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}
int countNode(){
    int count = 1;
    if(head == NULL){
        printf("Empty Linked List\n");
        return -1;
    }else{
        node* temp = head;
        while(temp -> next != head){
            count++;
            temp = temp -> next;
        }
        return count;
    }
}
int  main(){
    addNode();
    addNode();
    addNode();
    addNode();
    printLL();
    addFirst();
    printLL();
    int count = countNode();
    printf("Count : %d",count);
    return 0;  
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
