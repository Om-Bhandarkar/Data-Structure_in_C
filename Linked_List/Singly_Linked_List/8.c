#include<stdio.h>
#include<stdlib.h>
typedef struct  Node{
    int data;
    struct Node *next;
}node;
node *head = NULL;
node *createNode(){
    node* newNode = (node *)malloc(sizeof(node));
    printf("Enter Data :\n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;
} 
void addNode(){
    node *newNode = createNode();
    if(head == NULL){
        head = newNode;
    }else{
        node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void printLL(){
    node *temp = head;
    while (temp -> next != NULL)
    {
        printf("|%d|->",temp->data);
        temp = temp -> next;
    }
        printf("|%d|\n",temp->data);
}
void addAtFirst(){
    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter Data at first position : \n");
    scanf("%d",&newNode ->data);
    newNode -> next = head;
    head = newNode;
}
void addAtLast(){
    printf("For Last Node");
    node *newNode = createNode();
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp -> next;
    }
    temp-> next=newNode;
    
    // addNode();

    /* 
    -------Not Working--------

    node *newNode = (node *)malloc(sizeof(node));
    printf("Enter Data at Last position :\n");
    scanf("%d",&newNode->data);
    node *temp = head;
    while(temp!=NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;

    */

}
int countNode(){
    int count = 0;
    if(head == NULL){
        printf("Linked List is Empty\n");
    }
    node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    printf("Count = %d\n",count);
}
void deleteAtFirst(){
    node*temp = head;
    head = head -> next;
    free(temp);
}
void deleteAtLast(){
    node *temp1 = head;
    while(temp1->next->next!=NULL){
        temp1=temp1->next;
    }
    free(temp1->next);
    temp1->next=NULL;
}
int main(){
    int node;
    printf("How Many Node You Have Created ?\n");
    scanf("%d",&node);
    for(int i=1;i<=node;i++){
        addNode();
    }
    printLL();
    addAtFirst();
    printLL();
    countNode();
    addAtLast();
    printLL();
    countNode();
    deleteAtFirst();
    printLL();
    deleteAtLast();
    printLL();
}