#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 256
#define MAX_CHOICES 4
#define FILENAME "questions.txt"

// Data Structures
typedef struct Question {
    char text[MAX_TEXT];
    char choices[MAX_CHOICES][MAX_TEXT];
    struct Question* next;
} Question;

// Linked List Head
Question* head = NULL;

// Utility Functions
Question* create_question(const char* text, char choices[MAX_CHOICES][MAX_TEXT]) {
    Question* q = (Question*)malloc(sizeof(Question));
    strncpy(q->text, text, MAX_TEXT);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strncpy(q->choices[i], choices[i], MAX_TEXT);
    }
    q->next = NULL;
    return q;
}

void add_question() {
    char qtext[MAX_TEXT];
    char choices[MAX_CHOICES][MAX_TEXT];

    printf("Enter the question text: ");
    fgets(qtext, MAX_TEXT, stdin);
    qtext[strcspn(qtext, "\n")] = 0;

    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("Enter choice %c: ", 'A' + i);
        fgets(choices[i], MAX_TEXT, stdin);
        choices[i][strcspn(choices[i], "\n")] = 0;
    }

    Question* q = create_question(qtext, choices);
    if (!head) {
        head = q;
    } else {
        Question* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = q;
    }
    printf("Question added successfully.\n");
}

void list_questions() {
    int i = 1;
    Question* current = head;
    while (current) {
        printf("%d. %s\n", i++, current->text);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("   %c) %s\n", 'A' + j, current->choices[j]);
        }
        current = current->next;
    }
    if (i == 1) printf("No questions available.\n");
}

Question* get_question_by_index(int index) {
    Question* current = head;
    int i = 1;
    while (current) {
        if (i == index) return current;
        current = current->next;
        i++;
    }
    return NULL;
}

void edit_question() {
    list_questions();
    printf("Enter the number of the question to edit: ");
    int index;
    scanf("%d", &index);
    getchar(); // Clear newline
    Question* q = get_question_by_index(index);
    if (!q) {
        printf("Invalid question number.\n");
        return;
    }

    printf("Do you want to edit the (1) Question or (2) Choices? Enter 1 or 2: ");
    int choice;
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("Enter new question text: ");
        char new_text[MAX_TEXT];
        fgets(new_text, MAX_TEXT, stdin);
        new_text[strcspn(new_text, "\n")] = 0;
        strncpy(q->text, new_text, MAX_TEXT);
        printf("Question updated.\n");
    } else if (choice == 2) {
        printf("Which choice do you want to edit? (A-D): ");
        char c;
        scanf(" %c", &c);
        getchar();
        int ci = c - 'A';
        if (ci >= 0 && ci < MAX_CHOICES) {
            printf("Enter new text for choice %c: ", c);
            fgets(q->choices[ci], MAX_TEXT, stdin);
            q->choices[ci][strcspn(q->choices[ci], "\n")] = 0;
            printf("Choice %c updated.\n", c);
        } else {
            printf("Invalid choice.\n");
        }
    } else {
        printf("Invalid option.\n");
    }
}

void delete_question() {
    list_questions();
    printf("Enter the number of the question to delete: ");
    int index;
    scanf("%d", &index);
    getchar();

    Question *current = head, *prev = NULL;
    int i = 1;
    while (current) {
        if (i == index) {
            if (prev) prev->next = current->next;
            else head = current->next;
            free(current);
            printf("Question deleted.\n");
            return;
        }
        prev = current;
        current = current->next;
        i++;
    }
    printf("Invalid question number.\n");
}

void save_to_file() {
    FILE* file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }

    Question* current = head;
    while (current) {
        fprintf(file, "%s\n", current->text);
        for (int i = 0; i < MAX_CHOICES; i++) {
            fprintf(file, "%s\n", current->choices[i]);
        }
        current = current->next;
    }
    fclose(file);
    printf("Questions saved to file.\n");
}

void load_from_file() {
    FILE* file = fopen(FILENAME, "r");
    if (!file) return;

    char line[MAX_TEXT];
    while (fgets(line, MAX_TEXT, file)) {
        line[strcspn(line, "\n")] = 0;
        char choices[MAX_CHOICES][MAX_TEXT];
        for (int i = 0; i < MAX_CHOICES; i++) {
            fgets(choices[i], MAX_TEXT, file);
            choices[i][strcspn(choices[i], "\n")] = 0;
        }
        Question* q = create_question(line, choices);
        if (!head) {
            head = q;
        } else {
            Question* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = q;
        }
    }
    fclose(file);
}

// UI Menu
void menu() {
    load_from_file();
    while (1) {
        printf("\n--- Question Management System ---\n");
        printf("1. Add Question\n");
        printf("2. Edit Question\n");
        printf("3. Delete Question\n");
        printf("4. List All Questions\n");
        printf("0. Save and Exit\n");
        printf("Choose an option: ");

        int option;
        scanf("%d", &option);
        getchar();  // Consume newline

        switch (option) {
            case 1:
                add_question();
                break;
            case 2:
                edit_question();
                break;
            case 3:
                delete_question();
                break;
            case 4:
                list_questions();
                break;
            case 0:
                save_to_file();
                printf("Exiting.\n");
                return;
            default:
                printf("Invalid option.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
