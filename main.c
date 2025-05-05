#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

void MainMenu(int *main_choice){
    printf("\n===  Main Menu  ===\n");
    printf("[(1) Doctor       ]\n");
    printf("[(2) Patient      ]\n");
    printf("[(3) Exit         ]\n");
    printf("Enter choice: ");
    scanf("%d", main_choice);
    getchar();
}

int main() {

    int main_choice;

    while (1) {
        MainMenu(&main_choice);

        switch (main_choice) {
            case 1:
                clearTerminal();
                doctor_menu();
                break;
            case 2:
                clearTerminal();
                patient_menu();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }

        clearTerminal();
    }

    return 0;
}
