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
5)
Question: Implement a basic spell checker using BST where there will be user input of different words.
You have store those words in BST and display its inorder traversal.
You also have to take a word and search it in the tree. If you find th word, check if it has sibling and root. 
If sibling is present, print the sibling. If its root is present Uppercase the middle letter of word stored in root.
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
struct Node* createNode(char word[]){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word , word);
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, char word[]){
    if(root == NULL) return createNode(word);
    if(strcmp(word,root->word) < 0){
        root->left = insert(root->left,word);
    }else if(strcmp(word,root->word) > 0){
        root->right = insert(root->right, word);
    }
    return root;
}
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%s ", root->word);
        inorder(root->right);
    }
}
void capitalizeMid(char word[]){
    int len = strlen(word);
    if(len == 0) return;
    int mid = len/2;
    word[mid] = toupper(word[mid]);
}
void searchWord(struct Node* root, char word[], struct Node* parent, struct Node* mainRoot){
    if(root == NULL) return;
    int cmp = strcmp(word,root->word);
    if(cmp == 0){
        printf("Word Found!!");
        if(parent){
            if(parent->left == root && parent->right) printf("%s\n",parent->right->word);
            else if(parent->right == root && parent->left) printf("%s\n",parent->left->word);
            else printf("No siblings found\n");
        }
        if(mainRoot){
            capitalizeMid(mainRoot->word);
            printf("Root word now: %s\n",mainRoot->word);
        }
        return;
    }
    if(cmp < 0) searchWord(root->left,word,root,mainRoot);
    else searchWord(root->right,word,root,mainRoot);
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
     struct Node* root = NULL;
    int choice;
    char word[50];
    while (1) {
        printf("\n------ SPELL CHECKER MENU ------\n");
        printf("1. Insert Word\n");
        printf("2. Display Dictionary (Inorder)\n");
        printf("3. Search a Word\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                root = insert(root, word);
                break;

            case 2:
                printf("\nDictionary (Alphabetical Order):\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter word to search: ");
                scanf("%s", word);
                searchWord(root, word, NULL, root);
                break;

            case 4:
                printf("Exiting Spell Checker...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
