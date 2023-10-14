#include<stdio.h>
#include<stdlib.h>  
struct Employee{
    char empName[20];                   
    int empId;
    float rev;
    struct Employee *next;
};
struct Employee *head = NULL;

void addNode(){
    struct Employee *newNode = (struct Employee *)malloc(sizeof(struct Employee));
    printf("Enter Employee Name : ");
    scanf("%[^\n]",newNode->empName);
    printf("Enter Employee ID : ");
    scanf("%d",&newNode->empId);
    printf("Enter rev : ");
    scanf("%f",&newNode->rev);
    getchar();
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct Employee *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void printLL(){
    struct Employee *temp = head;
    while(temp != NULL){
        printf("| %s ",temp->empName);
        printf(" %d ",temp->empId);
        printf(" %f |",temp->rev);
        temp = temp -> next;
    } 
}
int main(){
    addNode();
    addNode();
    addNode();
    printLL();
}