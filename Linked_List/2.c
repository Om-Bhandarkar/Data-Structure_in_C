#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int stud_id;
    char branch[20];
    float cgpa;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->stud_id = 1206;
    strcpy(newNode->branch, "E&TC");
    newNode->cgpa = 7.0;
    newNode->next = NULL;
    head = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->stud_id = 1306;
    strcpy(newNode->branch, "COMP");
    newNode->cgpa = 8.0;
    newNode->next = NULL;
    head->next = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->stud_id = 1406;
    strcpy(newNode->branch, "MECH");
    newNode->cgpa = 9.0;
    newNode->next = NULL;
    head->next->next = newNode;

    struct Node *temp = head;
    while (temp -> next != NULL) {
        printf("|%d ", temp->stud_id);
        printf("%s ", temp->branch);
        printf("%f|->", temp->cgpa);
        temp = temp->next;
    }
    printf("|%d ", temp->stud_id);
    printf("%s ", temp->branch);
    printf("%f|", temp->cgpa);

    return 0;
}