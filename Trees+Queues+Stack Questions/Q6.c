/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/
/*
Menu Driven Program  
1.⁠ ⁠To insert a file name(.txt)   to the binary search tree. Insertion takes place based on the alphabetical order. 
2.⁠ ⁠Insert directory to bst same as above
3.⁠ ⁠To view a file to see if it exists
4.⁠ ⁠Delete a file from bst.
Every time you view it is appended to a double linked list. 
A file cannot have a file or directory as its child. It gives an error message otherwise. Now the directory and file name are just strings.
To segregate between dir and TXT . TXT will have .txt at the end.
*/
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *left, *right;
};

struct History {
    char name[50];
    struct History *next, *prev;
};

struct History* head = NULL;

int isFile(char name[]) {
    int len = strlen(name);
    return (len >= 4 && strcmp(name + len - 4, ".txt") == 0);
}

struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void append(char name[]) {
    struct History* newNode = (struct History*)malloc(sizeof(struct History));
    strcpy(newNode->name, name);
    newNode->next = newNode->prev = NULL;

    if (!head) {
        head = newNode;
        return;
    }
    struct History* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void displayHistory() {
    if (!head) {
        printf("No files viewed yet.\n");
        return;
    }
    printf("\n--- Recently Viewed Files ---\n");
    struct History* temp = head;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

struct Node* insert(struct Node* root, char name[]) {
    if (root == NULL)
        return createNode(name);

    if (isFile(root->name)) {
        printf("Error: Cannot insert under a file (%s cannot have children).\n", root->name);
        return root;
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0)
        root->left = insert(root->left, name);
    else if (cmp > 0)
        root->right = insert(root->right, name);
    else
        printf("Warning: %s already exists.\n", name);

    return root;
}

struct Node* search(struct Node* root, char name[]) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(name, root->name);
    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

struct Node* findMin(struct Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL)
        return root;

    int cmp = strcmp(name, root->name);
    if (cmp < 0)
        root->left = deleteNode(root->left, name);
    else if (cmp > 0)
        root->right = deleteNode(root->right, name);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            strcpy(root->name, temp->name);
            root->right = deleteNode(root->right, temp->name);
        }
    }
    return root;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%s\n", root->name);
        inorder(root->right);
    }
}

// --- Main Menu ---

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];
    struct Node* found;

    printf("File/Directory Management System (BST + DLL)\n");

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Insert File (.txt)\n");
        printf("2. Insert Directory\n");
        printf("3. View File/Directory\n");
        printf("4. Delete File/Directory\n");
        printf("5. Display BST (Alphabetical Order)\n");
        printf("6. Display View History\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                if (choice == 1 && !isFile(name)) {
                    printf("Error: File must end with .txt\n");
                    break;
                }
                if (choice == 2 && isFile(name)) {
                    printf("Error: Directory cannot end with .txt\n");
                    break;
                }
                root = insert(root, name);
                break;

            case 3:
                printf("Enter name to view: ");
                scanf("%s", name);
                found = search(root, name);
                if (found) {
                    printf("%s found in system.\n", found->name);
                    append(found->name);
                } else
                    printf("%s not found.\n", name);
                break;

            case 4:
                printf("Enter name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                printf("Deletion attempted.\n");
                break;

            case 5:
                printf("\n--- Files and Directories (Alphabetical Order) ---\n");
                inorder(root);
                break;

            case 6:
                displayHistory();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
