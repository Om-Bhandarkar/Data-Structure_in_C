/*
Q   WAP that searches for the 2nd last occurance of a particular element from a singly linear linked List 
    I/P :-
        Linked List :- |10|->|20|->|30|->|40|->|30|->|30|->|70|
        Enter Element :- 30
    O/p :-
        5
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
    printf("|%d|\n",temp->data);
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
void second_Last_Occurance(int ele){
    int count1 = 0;
    Node *temp = head;
    while(temp!=NULL){
        if(ele == temp -> data){
            count1++;
        }
        temp = temp -> next;
    }
    int count2 = 0;
    temp = head;
    while(count1 - 1){
        count2++;
        if(temp -> data == ele){
            count1--;
        }
        temp = temp -> next;
    }
    printf("Count = %d\n",count2);
}
int main(){
    int Node;
    printf("How many Node Add in Your Linked List : ");
    scanf("%d",&Node);
    for(int i=1;i<=Node;i++){
        addNode();
    }
    printLL();
    int ele;
    printf("Enter Element : ");
    scanf("%d",&ele);
    second_Last_Occurance(ele);
    return 0;
}