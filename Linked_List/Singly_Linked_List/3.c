#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct College {
    char branch[20];
    int stud_id;
    float cgpa;
    struct College *next;
};
struct College *head = NULL;

void addNode(){
    struct College *newNode = (struct College *)malloc(sizeof(struct College));
    printf("Enter your Branch : ");
    scanf("%[^\n]",newNode->branch);
    // fgets(newNode->branch,20,stdin);
    printf("Enter the Student ID : ");
    scanf("%d",&newNode->stud_id);
    printf("Enter your cgpa : ");
    scanf("%f",&newNode->cgpa);
    getchar();
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct College 
        8*temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void printLL(){
    struct College *temp = head;
    while(temp != NULL){
        printf("| %s ",temp->branch);
        printf(" %d ",temp->stud_id);
        printf(" %f | ",temp->cgpa);
        temp = temp -> next;
    }
}
int main() {
    addNode();
    addNode();
    addNode();
    printLL();
    return 0;
}