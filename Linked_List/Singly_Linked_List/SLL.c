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
    printf("For Last Node ");
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
int addAtPosition(int pos){
    int count = countNode();
    if(pos==1){
        addAtFirst();
    }else if (pos==count+1){
        addAtLast();
    }else{
        node *newNode = (node *)malloc(sizeof(node));
        node *temp = head;
        while(pos-2){
            temp = temp -> next;
            pos--;
        }
        newNode-> next = temp -> next;
        temp -> next = newNode;
    }
    return 0;
}
int deleteAtPos(int pos){
    int count = countNode();
    if(head==NULL || pos<=0 || pos>=count+1){
        printf("Invalid Position");
        return -1;
    }else if(pos==1){
        deleteAtFirst();
    }else if(pos==count){
        deleteAtLast();
    }else{
        node *temp =head;
        while(pos-2){
            temp = temp -> next;
            temp--;
        }
        node *temp1 = temp;
        temp -> next = temp -> next -> next;
        free(temp1 -> next);
    }
    return 0;
}
int main(){
    char choice;
    do{
        printf("==========Singly Linked List==========\n");
        printf("\t1.addNode\n\t2.addAtFirst\n\t3.addAtPosition\n\t4.addAtLast\n\t5.deleteAtFirst\n\t6.deleteAtLast\n\t7.printLL\n");
        int ch;
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch (ch){
        case 1:
                addNode();
                break;
        case 2:
                addAtFirst();
                break;
        case 3:
            {
                int pos;
                printf("Enter Position :\n");
                scanf("%d",&pos);
                addAtPosition(pos);
            }
                break;
        case 4:
                addAtLast();
                break;
        case 5:
                deleteAtFirst();
                break;
        case 6:
                deleteAtLast();
                break;
        case 7:
                printLL();
                break;
        
        default:
                printf("Wrong Input\n");
        }
        printf("Do you want to continue\n");
        getchar();
        scanf("%c",&choice);
    }while(choice=='y' || choice=='Y');
}