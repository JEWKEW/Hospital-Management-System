#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vari.h"

struct node* createnode(Patient *patient);
struct node* insert(struct node* root, Patient *patient);
void inorder(struct node* root, int* n);
void SearchTree(struct node* root, char *name, int *h);

struct node* createnode(Patient *patient) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed for node\n");
        exit(1);
    }

    newnode->patient = (Patient*)malloc(sizeof(Patient));
    if (!newnode->patient) {
        printf("Memory allocation failed for patient\n");
        exit(1);
    }

    strcpy(newnode->patient->fullname, patient->fullname);
    newnode->patient->age = patient->age;
    strcpy(newnode->patient->sex, patient->sex);
    newnode->patient->pior = patient->pior;
    strcpy(newnode->patient->phone, patient->phone);
    strcpy(newnode->patient->allergies, patient->allergies);
    strcpy(newnode->patient->conditions, patient->conditions);

    newnode->patient->next = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insert(struct node* root, Patient *patient) {
    if (root == NULL) {
        return createnode(patient);
    } else {
        if (strcmp(patient->fullname, root->patient->fullname) >= 0) {
            root->right = insert(root->right, patient);
        } else {
            root->left = insert(root->left, patient);
        }
        return root; 
    }
}

void inorder(struct node* root, int* n) {
    if (root != NULL) {
        inorder(root->left, n);

        printf("%-3d %-20s %-5d %-10s\n", (*n)++, root->patient->fullname, root->patient->age, root->patient->sex);

        inorder(root->right, n);
    }
}

void SearchTree(struct node* root, char *name, int *h) {

    if (root != NULL) {
        int c = strcmp(root->patient->fullname, name);
        if(c == 0){
            printf("Patient Information:\nName: %s\nAge: %d\nSex: %s\nPhone number: %s\nAllergies: %s\nCondition: %s\n", root->patient->fullname, root->patient->age, root->patient->sex, root->patient->phone, root->patient->allergies,root->patient->conditions);
            *h = 1;
            return;
        }else if(c<0) SearchTree(root->right, name, h);
        else SearchTree(root->left, name, h);
    }

    return;
}


