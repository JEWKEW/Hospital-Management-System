#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vari.h"
#include "tree.h"
#include "piorqueue.h"

#define FILENAME "patients.csv"

void waitForEnter();
void loadFromCSV(Patient **front, int *r);
void saveToCSV(Patient *front);
void PatientMenu();
void AddQueue(Queue *q);
void SearchQ(Queue *q);
void CancelQ(Queue *q);

void waitForEnter() {

    printf("Press Enter to continue: ");
    
    // while (getchar() != '\n');

    getchar();
}

void loadFromCSV(Patient **front, int *r)
{
    FILE *file = fopen(FILENAME, "r");
    if (!file)
    {
        printf("No CSV file found. Starting empty.\n");
        return;
    }

    char line[512];
    fgets(line, sizeof(line), file); // Skip header

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

void PatientMenu(){

    Queue q;
    q.front = NULL;
    q.r = -1;

    //loadFromCSV(&q.front, &q.r);

    int choice;
    char input[10];

    printf("\n----- Patient Queue System -----\n");
    printf("1. Add Queue\n");
    printf("2. Check Queue\n");
    printf("3. Cancel Queue\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
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
            AddQueue(&q);
            break;
        case 2:
            SearchQ(&q);
            break;
        case 3:
            CancelQ(&q);
            break;
        case 4:
            printf("Exiting and saving data...\n");
            //saveToCSV(q.front);
            return;
    }        

    PatientMenu(&choice, input);

    return;
}

void AddQueue(Queue *q){
    char fullname[40], sex[10], phone[15], allergies[100], conditions[100];
    int age;

    // Step 1: Gather personal info
    printf("Enter fullname: ");
    fgets(fullname, sizeof(fullname), stdin);
    fullname[strcspn(fullname, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &age);
    getchar();

    printf("Enter sex: ");
    fgets(sex, sizeof(sex), stdin);
    sex[strcspn(sex, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    while (strlen(phone) != 10 || strspn(phone, "0123456789") != 10)
    {
        printf("Invalid phone number. Enter exactly 10 digits: ");
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = '\0';
    }

    printf("Enter allergies (or 'none'): ");
    fgets(allergies, sizeof(allergies), stdin);
    allergies[strcspn(allergies, "\n")] = '\0';

    printf("Enter underlying conditions (or 'none'): ");
    fgets(conditions, sizeof(conditions), stdin);
    conditions[strcspn(conditions, "\n")] = '\0';

    // Step 2: Calculate priority score
    int pior = calculatePriority();

    // Step 3: Enqueue
    Enqueue(&q->front, fullname, age, sex, phone, allergies, conditions, pior, &q->r);
    saveToCSV(q->front);
    printf("Patient added and saved.\n");

    waitForEnter();

    return;
}

void SearchQ(Queue *q){
    Search((*q).front);

    waitForEnter();

    return;
}

void CancelQ(Queue *q){
    if (q->front == NULL)
        {
            printf("Queue is empty, cannot cancel!\n");
        }
        else
        {
            char name[40];
            printf("Enter name to delete from queue: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            if (DeleteByName(&q->front, name, &q->r))
            {
                saveToCSV(q->front);
                printf("Patient '%s' removed from queue.\n", name);
            }
            else
            {
                printf("Warning: Entered name does not match any patient in the queue.\n");
            }
        }

    waitForEnter();

    return;
}

int main()
{

    PatientMenu();

    return 0;
}