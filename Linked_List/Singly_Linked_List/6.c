#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void addNode(){
    struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter Data : ");
    scanf("%d",&newNode->data);
    newNode-> next=NULL;
    if(head==NULL){
        head = newNode;
    }else{
        struct Node *temp = head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next = newNode;
    } 
}
void printLL(){
    struct Node* temp = head;
    while(temp -> next  != NULL){
        printf("|%d|->",temp->data);
        temp=temp->next;
    }
    printf("|%d|",temp->data);
}
int main(){
    int Node;
    printf("How many Node Add in Your Linked List : ");
    scanf("%d",&Node);
    for(int i=1;i<=Node;i++){
        addNode();
    }
    printLL();
    return 0;
}