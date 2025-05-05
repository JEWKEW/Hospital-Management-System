#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctor.h"

void waitForEnter();
void PatientMenu();
void AddQueue(Queue *q);
void SearchQ(Queue *q);
void CancelQ(Queue *q);
void patient();

void PatientMenu(Queue *q){

    int choice;
    char input[10];

    while(1){
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
            confirm();
            continue;
        }

        switch (choice) {
            case 1:
                AddQueue(q);
                confirm();
                break;
            case 2:
                SearchQ(q);
                confirm();
                break;
            case 3:
                CancelQ(q);
                confirm();
                break;
            case 4:
                saveToCSV(q->front);
                clearTerminal();
                return;
        }        
    }

    return;
}

void patient(){

    Queue q;
    q.front = NULL;
    q.r = -1;

    loadFromCSV(&q.front, &q.r);

    PatientMenu(&q);

    return;
}

void AddQueue(Queue *q){
    char fullname[40], sex[10], phone[15], allergies[100], conditions[100], input[10];
    int age;

    // Step 1: Gather personal info
    printf("Enter fullname: ");
    fgets(fullname, sizeof(fullname), stdin);
    fullname[strcspn(fullname, "\n")] = '\0';

    printf("Enter age: ");
    fgets(input, 10, stdin);
    sscanf(input, "%d", &age);

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

    int pior = calculatePriority();

    Enqueue(&q->front, fullname, age, sex, phone, allergies, conditions, pior, &q->r);
    saveToCSV(q->front);
    printf("Patient added and saved.\n");

    return;
}

void SearchQ(Queue *q){
    Search((*q).front);

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

    return;
}