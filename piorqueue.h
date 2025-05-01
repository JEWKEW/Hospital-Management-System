#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vari.h"

Patient *createQ(char *fullname, int age, char *sex, int pior) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));

    strcpy(newPatient->fullname, fullname);
    newPatient->age = age;
    strcpy(newPatient->sex, sex);
    newPatient->pior = pior;
    newPatient->next = NULL;

    return newPatient;
}

void Enqueue(Patient **front, char *fullname, int age, char *sex, int pior, int *r) {
    if (*r == MAX - 1) {
        printf("Patient is full.\n");
        return;
    }

    Patient *newQ = createQ(fullname, age, sex, pior);

    if (*front == NULL || (*front)->pior < pior || 
        ((*front)->pior == pior && strcmp((*front)->fullname, fullname) > 0)) {
        newQ->next = *front;
        *front = newQ;
    } else {
        Patient *ptr = *front;
        while (ptr->next != NULL && 
               (ptr->next->pior > pior || 
               (ptr->next->pior == pior && strcmp(ptr->next->fullname, fullname) < 0))) {
            ptr = ptr->next;
        }
        newQ->next = ptr->next;
        ptr->next = newQ;
    }

    (*r)++;
}

void Dequeue(Patient **front, int *r) {
    if (*front == NULL) {
        printf("Patient is empty.\n");
        return;
    }

    Patient *temp = *front;
    printf("Dequeued: Fullname: %s, Priority: %d\n", temp->fullname, temp->pior);
    *front = (*front)->next;
    free(temp);
    (*r)--;
}

void Peek(Patient *front) {
    if (front == NULL) {
        printf("Patient is empty.\n");
        return;
    }
    printf("Next queue is Fullname: %s, Priority: %d\n", front->fullname, front->pior);
}

void DisplayList(Patient *front) {
    if (front == NULL) {
        printf("Patient is empty.\n");
        return;
    }

    Patient *ptr = front;
    int n = 1;
    while (ptr != NULL) {
        printf("%d. Fullname: %s, Age: %d, Priority: %d\n",n++, ptr->fullname, ptr->age, ptr->pior);
        ptr = ptr->next;
    }
}

void Search(Patient *front) {

    if (front == NULL) {
        printf("Patient is empty.\n");
        return;
    }
    
    printf("What is your name: ");
    char name[40];
    scanf("%[^\n]s", &name);

    int n = 0;

    Patient *ptr = front;
    while (ptr != NULL) {
        if(strcmp(ptr->fullname, name) == 0){
            printf("Your queue will arrive in %d queues\n", n);
            return;
        }
        n++;
        ptr = ptr->next;
    }

    printf("Your name not in the Queue\n");
    return;
}