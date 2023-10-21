#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *createNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->prev = NULL;
    printf("Enter the data : ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void addNode()
{
    node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        head->prev = head;
        head->next = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->prev = newNode;
        temp->next = newNode;
        newNode->prev = head;
        newNode->next = head;
    }
}
int printLL()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Nothing to print\n");
        return -1;
    }
    else
    {
        while (temp->next != head)
        {
            printf("|%d|->", temp->data);
            temp = temp->next;
        }
        printf("|%d|\n", temp->data);
        return 0;
    }
}
void addFirst()
{
    node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        head->prev = head;
        head->next = head;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
int countNode()
{
    int count = 1;
    if (head == NULL)
    {
        printf("Empty Linked List\n");
        return -1;
    }
    else
    {
        node *temp = head;
        while (temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}
int addAtPos(int pos)
{
    node *newNode = createNode();
    int count = countNode();
    if (pos <= 0 || pos >= count + 2)
    {
        printf("Wrong Position\n");
        return -1;
    }
    else
    {
        if (pos == 1)
        {
            addFirst();
        }
        else if (pos == count + 1)
        {
            addNode();
        }
        else
        {
            node *temp = head;
            while (pos - 2)
            {
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
            newNode->prev = temp;
        }
        return 0;
    }
}
int delFirst()
{
    if (head == NULL)
    {
        printf("Empty Linked List\n");
        return -1;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return 0;
    }
    else
    {
        // With Temp
        /*
        node* temp = head;
        temp -> prev -> next = head -> next;
        head = head -> next;
        head -> prev = temp -> prev;
        free(temp);
        return 0;
        */

        // Without Temp
        head = head->next;
        head->prev = head->prev->prev;
        free(head->prev->next);
        head->prev->next = head;
    }
}
int delLast()
{
    if (head == NULL)
    {
        printf("Empty linked List\n");
        return -1;
    }
    else
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->prev->next = head;
            head->prev = temp->prev;
            free(temp);
        }
        return 0;
    }
}
int main()
{
    addNode();
    addNode();
    addNode();
    addNode();
    printLL();
    // Add at First
    addFirst();
    printLL();
    int count = countNode();
    printf("Count : %d\n", count);
    int pos1;
    printf("Enter Position : \n");
    scanf("%d", &pos1);
    // Add at Position
    addAtPos(pos1);
    printLL();
    printf("Node Add SuccessFully.....!\n");
    // Delete First Node
    delFirst();
    printLL();
    printf("First Node Deleted SuccessFully.....!\n");
    // Delete Last Node
    delLast();
    printLL();
    printf("Last Node Deleted SuccessFully.....!\n");
    return 0;
}
