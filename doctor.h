#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vari.h"
#include "tree.h"
#include "piorqueue.h"
#define FILENAME "File/patients.csv"
#define CUREFILENAME "File/cure_patient.csv"

void clearTerminal();
void waitForEnter();
void confirm();
void MoveData(Queue *patientQueue, node **patientData);
void DoctorMenu(Queue *patientQueue, node **patientData);
void DisplayCurePatient(node *patientData);
void doctor();
void loadFromCSV(Patient **front, int *r);
void saveToCSV(Patient *front);
void write(struct node* root, FILE *file);
void saveCurePatient(struct node* root);

void loadFromCSV(Patient **front, int *r)
{
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("No CSV file found. Starting empty.\n");
        return;
    }

    char line[512];
    fgets(line, sizeof(line), file); 

    while (fgets(line, sizeof(line), file))
    {
        char fullname[40], sex[10], phone[15], allergies[100], conditions[100];
        int age, pior;

        if (sscanf(line, "%[^,],%d,%[^,],%[^,],%[^,],%[^,],%d",
                   fullname, &age, sex, phone, allergies, conditions, &pior) == 7)
        {
            Enqueue(front, fullname, age, sex, phone, allergies, conditions, pior, r);
        }
    }

    fclose(file);
}

void saveToCSV(Patient *front)
{
    FILE *file = fopen(FILENAME, "w");
    if (!file)
    {
        printf("Error opening CSV file for writing.\n");
        return;
    }

    fprintf(file, "fullname,age,sex,phone,allergies,conditions,pior\n");

    Patient *ptr = front;
    while (ptr != NULL)
    {
        fprintf(file, "%s,%d,%s,%s,%s,%s,%d\n", ptr->fullname, ptr->age, ptr->sex,
                ptr->phone, ptr->allergies, ptr->conditions, ptr->pior);
        ptr = ptr->next;
    }

    fclose(file);
}

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void waitForEnter() {
    int c;
    printf("Press Enter to continue: ");

    if (getchar() != '\n') {
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

void confirm(){
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

void DoctorMenu(Queue *patientQueue, node **patientData){

    int choice;
    char input[10];

    while(1){
        printf("\n----- Doctor System -----\n");
        printf("1. Display all Queue\n");
        printf("2. Cure Patient\n");
        printf("3. Display Cured Patients\n");
        printf("4. Back\n");
        printf("Enter choice number: ");
        fgets(input, sizeof(input), stdin);
        
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
        {
            printf("Please enter a valid option.\n");

        }

        if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 4)
        {
            printf("'%s' is not a valid option. Please choose again.\n", input);
        }

        switch (choice) {
            case 1:
                DisplayList(patientQueue->front);
                confirm();
                break;

            case 2:
                MoveData(patientQueue, patientData);
                confirm();
                break;

            case 3:
                DisplayCurePatient(*patientData);
                break;

            case 4:
                return;  
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n\n");
                confirm();
                continue;
                break;
        }       
    }

    return;
}

void DisplayCurePatient(node *patientData){
    int choice;
    char input[10];

    while (1)
    {
        printf("\n");
        printf("1.All Cured Patient\n");
        printf("2.Search\n");
        printf("3.Back\n");
        printf("Enter choice number: ");
        fgets(input, sizeof(input), stdin);
        printf("\n");

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
        {
            printf("Please enter a valid option.\n");
            confirm();
            continue;
        }

        if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 4)
        {
            printf("'%s' is not a valid option. Please choose again.\n", input);
            confirm();
            continue;
        }

        if(choice == 1) {
            if(patientData == NULL) printf("No Cured Patient\n");
            else {
                printf("%-3s %-20s %-5s %-10s\n", "", "NAME", "AGE", "SEX");
                int n = 1;
                inorder(patientData, &n);
                printf("\n");
            }
        }
        else if(choice == 2){
            if(patientData == NULL) printf("No Cured Patient\n");
            else{
                char name[40];
                int h = 0;
                printf("Enter Search Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("\n");
                SearchTree(patientData, name, &h);
    
                if(h == 0) printf("%s Not Found.\n", name);
                printf("\n");
            }
        }
        else if(choice == 3) {clearTerminal(); return;}

        confirm();
    }

    return;
}

void doctor(){
    Queue patientQueue;
    patientQueue.front = NULL;
    patientQueue.r = -1;
    node *patientData = NULL;

    loadFromCSV(&patientQueue.front, &patientQueue.r);

    DoctorMenu(&patientQueue, &patientData);

    saveToCSV(patientQueue.front);
    saveCurePatient(patientData);

    clearTerminal();

    return;
}

void write(struct node* root, FILE *file) {
    if (root != NULL) {
        write(root->left, file);

        fprintf(file, "%s,%d,%s,%s,%s,%s,%d\n", root->patient->fullname, root->patient->age, root->patient->sex,
            root->patient->phone, root->patient->allergies, root->patient->conditions, root->patient->pior);

        write(root->right, file);
    }
}

void saveCurePatient(struct node* root)
{
    FILE *file = fopen(CUREFILENAME, "w");
    if (!file)
    {
        printf("Error opening CSV file for writing.\n");
        return;
    }

    fprintf(file, "fullname,age,sex,phone,allergies,conditions,pior\n");

    node *ptr = root;
    write(root, file);

    fclose(file);
}