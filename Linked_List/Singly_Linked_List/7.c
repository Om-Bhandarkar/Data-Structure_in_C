#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
int countNode(){
    struct Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}
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
void addFirst(){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Node Data : \n");
    scanf("%d",&newNode->data);
    newNode -> next = head;
    head = newNode;
}
void printLL(){
    struct Node* temp = head;
    while(temp -> next  != NULL){
        printf("|%d|->",temp->data);
        temp=temp->next;
    }
    printf("|%d|\n",temp->data);
}
int main(){
    // int Node;
    // printf("How many Node Add in Your Linked List : ");
    // scanf("%d",&Node);
    // for(int i=1;i<=Node;i++){
    //     addNode();
    // }
    addNode();
    addNode();
    addNode();
    printLL();
    addFirst();
    printLL();
    return 0;
}