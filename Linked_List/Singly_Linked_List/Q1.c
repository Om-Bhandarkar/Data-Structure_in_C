/*
Q.  WAP that searches for the first occurance of a particular element from a singly linear linked list.
    I/P :
        Linked List :- |10|->|20|->|30|->|40|->|50|
        Enter Element :- 30
    O/P :
        3
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
struct Node *head = NULL;

void addNode(){
    Node *newNode = (Node *) malloc (sizeof(Node));
    printf("Enter Data : ");
    scanf("%d",&newNode->data);
    newNode-> next=NULL;
    if(head==NULL){
        head = newNode;
    }else{
        Node *temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = newNode;
    } 
}
void printLL(){
    Node* temp = head;
    while(temp -> next  != NULL){
        printf("|%d|->",temp->data);
        temp=temp->next;
    }
    printf("|%d|",temp->data);
}
int countNode(){
    int count = 0;
    Node *temp = head;
    while(temp  -> next != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}
void foccurance(int ele){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        count++;
        if(temp -> data == ele){
            break;
        }
        temp = temp -> next;
    }
    printf("Count = %d\n",count);
}
int main(){
    int Node;
    printf("How many Node Add in Your Linked List : ");
    scanf("%d",&Node);
    for(int i=1;i<=Node;i++){
        addNode();
    }
    int ele;
    printf("Enter Element : ");
    scanf("%d",&ele);
    foccurance(ele);
    printLL();
    return 0;
}