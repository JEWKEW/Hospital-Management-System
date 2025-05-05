#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#define CSV_FILE "File/account.csv"
#define MAX_LEN 100

void register_patient();
int login_patient(const char *username, const char *password);
int is_doctor(const char *username, const char *password);
void doctor_panel();
void patient_panel(const char *username);
void patient_menu();
void doctor_menu();

void register_patient() {
    char username[MAX_LEN], password[MAX_LEN], confirm_password[MAX_LEN];

    printf("Name: ");
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = '\0';

    FILE *fp = fopen(CSV_FILE, "r");
    char line[MAX_LEN], existing_user[MAX_LEN];
    if (fp) {
        while (fgets(line, sizeof(line), fp)) {
            sscanf(line, "%[^,],%*s", existing_user);
            if (strcmp(existing_user, username) == 0) {
                printf("Username already exists please try a different one.\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    do {
        printf("Password (at least 4 characters): ");
        fgets(password, MAX_LEN, stdin);
        password[strcspn(password, "\n")] = '\0';

        if (strlen(password) < 4) {
            printf("Password too short. Try again.\n");
            continue;
        }

        printf("Confirm Password: ");
        fgets(confirm_password, MAX_LEN, stdin);
        confirm_password[strcspn(confirm_password, "\n")] = '\0';

        if (strcmp(password, confirm_password) != 0) {
            printf("Passwords do not match. Try again.\n");
        } else {
            break;
        }
    } while (1);

    fp = fopen(CSV_FILE, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(fp, "%s,%s\n", username, password);
    fclose(fp);
    printf("Patient account created successfully.\n");
}

int login_patient(const char *username, const char *password) {
    FILE *fp = fopen(CSV_FILE, "r");
    if (fp == NULL) return 0;

    char line[MAX_LEN];
    char file_user[MAX_LEN], file_pass[MAX_LEN];

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%[^\n]", file_user, file_pass);
        if (strcmp(username, file_user) == 0 && strcmp(password, file_pass) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int is_doctor(const char *username, const char *password) {
    return strcmp(username, "d") == 0 && strcmp(password, "1234") == 0;
}

void doctor_panel() {
    printf("Doctor Panel!\n");
    doctor();
}

void patient_panel(const char *username) {
    printf("%s You in Patient Panel.\n", username);
    patient();
}

void doctor_menu() {
    int choice;
    char username[MAX_LEN], password[MAX_LEN], input[10];

    while (1) {
        printf("\n---  Doctor Menu  ---\n");
        printf("~~~~~~~~~~~~~~~~~~~~~\n");
        printf("[(1) Login as Doctor]\n");
        printf("[(2) Back           ]\n");
        printf("Enter choice: ");
        fgets(input, 10, stdin);
        sscanf(input, "%d", &choice);  

        if (choice == 1) {
            printf("Doctor Username: ");
            fgets(username, MAX_LEN, stdin);
            username[strcspn(username, "\n")] = '\0';

            printf("Doctor Password: ");
            fgets(password, MAX_LEN, stdin);
            password[strcspn(password, "\n")] = '\0';

            if (is_doctor(username, password)) {
                printf("Doctor login successful.\n");
                confirm();
                doctor_panel();
            } else {
                printf("Invalid doctor credentials.\n");
                confirm();
            }
        } else if (choice == 2) {
            return;
        } else {
            printf("Invalid choice.\n");
            confirm();
        }
    }
}

void patient_menu() {
    int choice;
    char username[MAX_LEN], password[MAX_LEN], input[10];

    while (1) {
        printf("\n-----   Patient Menu   -----\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("[(1) Login as Patient       ]\n");
        printf("[(2) Create Patient Account ]\n");
        printf("[(3) Back                   ]\n");
        printf("Enter choice: ");
        fgets(input, 10, stdin);
        sscanf(input, "%d", &choice);  

        switch (choice) {
            case 1:
                printf("Input Name: ");
                fgets(username, MAX_LEN, stdin);
                username[strcspn(username, "\n")] = '\0';

                printf("Input Password: ");
                fgets(password, MAX_LEN, stdin);
                password[strcspn(password, "\n")] = '\0';

                if (login_patient(username, password)) {
                    printf("Patient login successful.\n");
                    confirm();
                    patient_panel(username);
                } else {
                    printf("Invalid patient credentials.\n");
                    confirm();
                }
                break;
            case 2:
                register_patient();
                confirm();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice.\n");
                confirm();
        }
    }
}
