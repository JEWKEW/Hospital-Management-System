#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piorqueue.h"
#include "tree.h"

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void waitForEnter() {
    printf("Press Enter to continue: ");
    
    while (getchar() != '\n');

    getchar();
}

void confirm(){
    char a;
    // printf("Enter any keys to continue: ");
    // scanf(" %c", &a);
    waitForEnter();
    clearTerminal();
    return;
}

void MoveData(Queue *patientQueue, node **patientData) {
    if (patientQueue->front != NULL) {
        Patient *temppatient = patientQueue->front; 
        *patientData = insert(*patientData, temppatient); 
        Dequeue(&patientQueue->front, &patientQueue->r);
    }
}

void DoctorMenu(int *choice){
    printf("Hi, Doctor. What can I do for you?\n");
    printf("1.Display all Queue\n");
    printf("2.Cure Patient\n");
    printf("3.Display Cure Patient\n");
    printf("4.Back\n");
    printf("Enter choice number: ");

    scanf("%d", choice);
    clearTerminal();

    return;
}

void DisplayCurePatient(node *patientData){
    int a = 0;
    printf("\n");
    printf("1.All Cured Patient\n");
    printf("2.Search\n");
    printf("3.Back\n");
    printf("Enter choice number: ");
    scanf("%d", &a);

    if(a == 1) {
        if(patientData == NULL) printf("No Cured Patient\n");
        else {
            printf("%-3s %-20s %-5s %-10s\n", "", "NAME", "AGE", "SEX");
            int n = 1;
            inorder(patientData, &n);
        }
    }
    else if(a == 2){
        if(patientData == NULL) printf("No Cured Patient\n");
        else{
            char name[40];
            int h = 0;
            printf("Enter Search Name: ");
            scanf(" %[^\n]s", name); 
            SearchTree(patientData, name, &h);

            if(h == 0) printf("%s Not Found.\n", name);
        }
    }
    else if(a == 3) return;
    else DisplayCurePatient(patientData);

    confirm();
    return;
}

int main() {
    Queue patientQueue;
    patientQueue.front = NULL;
    patientQueue.r = -1;
    node *patientData = NULL;
    int choice = 0;

    Enqueue(&patientQueue.front, "Aomchai Dee", 35, "Male", 2, &patientQueue.r);
    Enqueue(&patientQueue.front, "Bomsri Jai", 60, "Female", 1, &patientQueue.r);
    Enqueue(&patientQueue.front, "Cichai Mee", 20, "Male", 3, &patientQueue.r);
    Enqueue(&patientQueue.front, "Daree Suk", 45, "Female", 2, &patientQueue.r);

    DoctorMenu(&choice);

    while(choice != 4){
        switch (choice)
        {
        case 1:
            DisplayList(patientQueue.front);
            confirm();
            break;
        case 2:
            MoveData(&patientQueue, &patientData);
            break;
        case 3:
            DisplayCurePatient(patientData);
            break;
        case 4:
            return 0;
            break;
        default:
            DoctorMenu(&choice);
            break;
        }

        //printf("\n");
        DoctorMenu(&choice);
    }

    // DisplayList(patientQueue.front);
    // printf("\n");

    // Peek(patientQueue.front);

    // Search(patientQueue.front);

    // MoveData(&patientQueue, &patientData);
    // MoveData(&patientQueue, &patientData);
    // MoveData(&patientQueue, &patientData);
    // MoveData(&patientQueue, &patientData);
    

    // DisplayList(patientQueue.front);
    // printf("\n");

    // inorder(patientData);

    return 0;
}

