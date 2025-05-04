#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define CSV_FILE "patients.csv"

// Declarations
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

    // Check if username already exists
    FILE *fp = fopen(CSV_FILE, "r");
    char line[MAX_LEN], existing_user[MAX_LEN];
    if (fp) {
        while (fgets(line, sizeof(line), fp)) {
            sscanf(line, "%[^,],%*s", existing_user);
            if (strcmp(existing_user, username) == 0) {
                printf("Username already exists. Try a different one.\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    // Password input and validation
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

    // Save to file
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
    return strcmp(username, "doctor") == 0 && strcmp(password, "doctor123") == 0;
}

void doctor_panel() {
    printf("Welcome to the Doctor Panel!\n");
    // Extend functionality here
}

void patient_panel(const char *username) {
    printf("Welcome, %s! You're in the Patient Panel.\n", username);
    // Extend functionality here
}

void doctor_menu() {
    int choice;
    char username[MAX_LEN], password[MAX_LEN];

    while (1) {
        printf("\n---  Doctor Menu  ---\n");
        printf("~~~~~~~~~~~~~~~~~~~~~\n");
        printf("[(1) Login as Doctor]\n");
        printf("[(2) Back           ]\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        if (choice == 1) {
            printf("Doctor Username: ");
            fgets(username, MAX_LEN, stdin);
            username[strcspn(username, "\n")] = '\0';

            printf("Doctor Password: ");
            fgets(password, MAX_LEN, stdin);
            password[strcspn(password, "\n")] = '\0';

            if (is_doctor(username, password)) {
                printf("Doctor login successful.\n");
                doctor_panel();
            } else {
                printf("Invalid doctor credentials.\n");
            }
        } else if (choice == 2) {
            return;
        } else {
            printf("Invalid choice.\n");
        }
    }
}

void patient_menu() {
    int choice;
    char username[MAX_LEN], password[MAX_LEN];

    while (1) {
        printf("\n-----   Patient Menu   -----\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("[(1) Login as Patient       ]\n");
        printf("[(2) Create Patient Account ]\n");
        printf("[(3) Back                   ]\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

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
                    patient_panel(username);
                } else {
                    printf("Invalid patient credentials.\n");
                }
                break;
            case 2:
                register_patient();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

#endif  // SYSTEM_H
