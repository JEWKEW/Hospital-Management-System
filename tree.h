#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vari.h"

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

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s %d\n", root->patient->fullname, root->patient->age);
        inorder(root->right);
    }

    return;
}
