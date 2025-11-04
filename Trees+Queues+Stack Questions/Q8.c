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
Spell Checker
Create a basic Spell Checker using BST. 
1.⁠ ⁠read words into the BST, and then print them in alphabetical order
2.⁠ ⁠Read a word from the user and check via the bst if it is spelled correctly. Or if it is found
3.⁠ ⁠check if the entered word has siblings if it exists, if it does, have its parent node's middle lettter capitalised.
*/
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node{
    char word[50];
    struct Node* left, *right;
};
struct Node* createNode(char word[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, char word[]) {
    if (root == NULL)
        return createNode(word);
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word);
    return root;
}
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%s ", root->word);
        inorder(root->right);
    }
}
void capitalize(char word[]){
    int len = strlen(word);
    if(len == 0) return;
    word[len/2] = toupper(word[len/2]);
}
void search(struct Node* root, char key[], struct Node* parent){
    if(!root) return;
    int cmp = strcmp(key,root->word);
    if(cmp == 0){
        printf("Word %s found and spelled correctly\n",root->word);
        if(parent){
            if(parent->left == root && parent->right){
                printf("Sibling exists %s\n",parent->right->word);
            }else if(parent->right == root && parent->left){
                printf("Sibling exists %s\n",parent->left->word);
            }else{
                printf("He is lonely like me :(");
            }
            capitalize(parent->word);
            printf("New parent %s\n",parent->word);
        }else{
            printf("Aage chal lodu\n");
        }
        return;
    }
    if (cmp < 0)
        search(root->left, key, root);
    else
        search(root->right, key, root);
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
    struct Node* root = NULL;
    char word[50];
    int choice;
    while (1) {
        printf("\n------ SPELL CHECKER MENU ------\n");
        printf("1. Insert Word\n");
        printf("2. Display Dictionary (Inorder)\n");
        printf("3. Search Word\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                root = insert(root, word);
                break;

            case 2:
                printf("Dictionary (Alphabetical): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter word to search: ");
                scanf("%s", word);
                search(root, word, NULL);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
