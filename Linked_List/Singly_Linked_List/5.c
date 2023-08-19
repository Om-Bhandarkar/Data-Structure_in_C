#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void addNode(){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct Node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

}
int main(){
    addNode();
    addNode();
    return 0;
}
