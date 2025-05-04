#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vari.h"
#include "tree.h"
#include "piorqueue.h"

#define FILENAME "patients.csv"

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

int main()
{
    Queue q;
    q.front = NULL;
    q.r = -1;

    loadFromCSV(&q.front, &q.r);

    int choice;
    char input[10]; // for reading input safely

    do
    {
        printf("\n----- Patient Queue System -----\n");
        printf("1. Add Queue\n");
        printf("2. Check Queue\n");
        printf("3. Cancel Queue\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        // If input is empty, skip this iteration
        if (strlen(input) == 0)
        {
            printf("Please enter a valid option.\n");
            continue;
        }

        if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 4)
        {
            printf("'%s' is not a valid option. Please choose again.\n", input);

            // Prompt user to press 'X' or 'x' to go back to the main menu
            char backInput[10];
            do
            {
                printf("Please press X or x to go back to Patient Queue System: ");
                fgets(backInput, sizeof(backInput), stdin);
                // Remove newline
                backInput[strcspn(backInput, "\n")] = '\0';
            } while (strlen(backInput) != 1 || (backInput[0] != 'x' && backInput[0] != 'X'));

            // After valid 'x' or 'X', continue the loop to show the main menu again
            continue; // Return to the beginning of the loop after pressing 'x' or 'X'
        }

        switch (choice)
        {
        case 1:
        {
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
            Enqueue(&q.front, fullname, age, sex, phone, allergies, conditions, pior, &q.r);
            saveToCSV(q.front);
            printf("Patient added and saved.\n");
            break;
        }

        case 2:
        {
            Search(q.front);

            printf("Press X or x to go back to Patient Queue System: ");
            char back;
            getchar(); // Clear leftover newline
            scanf("%c", &back);

            while (back != 'x' && back != 'X')
            {
                printf("Invalid input. Please press X or x to go back: ");
                getchar(); // Clear leftover newline
                scanf("%c", &back);
            }
            break;
        }

        case 3:
        {
            if (q.front == NULL)
            {
                printf("Queue is empty, cannot cancel!\n");
            }
            else
            {
                char name[40];
                printf("Enter name to delete from queue: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                if (DeleteByName(&q.front, name, &q.r))
                {
                    saveToCSV(q.front);
                    printf("Patient '%s' removed from queue.\n", name);
                }
                else
                {
                    printf("Warning: Entered name does not match any patient in the queue.\n");
                }
            }

            // Prompt to go back
            char backInput[10];
            do
            {
                printf("Press X or x to go back to Patient Queue System: ");
                fgets(backInput, sizeof(backInput), stdin);
                backInput[strcspn(backInput, "\n")] = '\0';
            } while (strlen(backInput) != 1 || (backInput[0] != 'x' && backInput[0] != 'X'));

            break;
        }

        case 4:
            printf("Exiting and saving data...\n");
            saveToCSV(q.front);
            break;
        }

    } while (choice != 4);

    return 0;
}