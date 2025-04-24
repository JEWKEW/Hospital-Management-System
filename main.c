#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piorqueue.h"
#include "tree.h"

void MoveData(Queue *patientQueue, node **patientData) {
    if (patientQueue->front != NULL) {
        Patient *temppatient = patientQueue->front; 
        *patientData = insert(*patientData, temppatient); 
        Dequeue(&patientQueue->front, &patientQueue->r);
    }
}

int main() {
    Queue patientQueue;
    patientQueue.front = NULL;
    patientQueue.r = -1;
    node *patientData = NULL;

    Enqueue(&patientQueue.front, "Aomchai Dee", 35, "Male", 2, &patientQueue.r);
    Enqueue(&patientQueue.front, "Bomsri Jai", 60, "Female", 1, &patientQueue.r);
    Enqueue(&patientQueue.front, "Cichai Mee", 20, "Male", 3, &patientQueue.r);
    Enqueue(&patientQueue.front, "Daree Suk", 45, "Female", 2, &patientQueue.r);

    DisplayList(patientQueue.front);
    printf("\n");

    Peek(patientQueue.front);

    Search(patientQueue.front);

    MoveData(&patientQueue, &patientData);
    MoveData(&patientQueue, &patientData);
    MoveData(&patientQueue, &patientData);
    MoveData(&patientQueue, &patientData);
    

    DisplayList(patientQueue.front);
    printf("\n");

    inorder(patientData);
    printf("ไอเหี้ยบัง");

    return 0;
}

//Atip Test