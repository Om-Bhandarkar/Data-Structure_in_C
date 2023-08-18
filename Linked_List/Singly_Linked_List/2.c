#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct College {
    int stud_id;
    char branch[20];
    float cgpa;
    struct College *next;
};

int main() {
    struct College *head = NULL;

    struct College *newNode = (struct College *)malloc(sizeof(struct College));
    newNode->stud_id = 1206;
    strcpy(newNode->branch, "E&TC");
    newNode->cgpa = 7.0;
    newNode->next = NULL;
    head = newNode;

    newNode = (struct College *)malloc(sizeof(struct College));
    newNode->stud_id = 1306;
    strcpy(newNode->branch, "COMP");
    newNode->cgpa = 8.0;
    newNode->next = NULL;
    head->next = newNode;

    newNode = (struct College *)malloc(sizeof(struct College));
    newNode->stud_id = 1406;
    strcpy(newNode->branch, "MECH");
    newNode->cgpa = 9.0;
    newNode->next = NULL;
    head->next->next = newNode;

    struct College *temp = head;
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