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
Question: Create a menu-driven program to manage binary tree nodes in a stack with the following functionalities: Create a stack of nodes: Implement push, pop, and display functionality. 
The display should show the top of the stack after each operation and the address of each node. 
Create a binary tree: Convert a postfix expression into a binary expression tree using the stack and display it in infix (inorder) notation.
Preorder Display: Display the binary tree in prefix (preorder) notation. 
Exit: Option to exit the program. Doubly Linked List Transformation and Operations
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
struct Node{
    char data;
    struct Node* left , *right;
};
struct Node* stack[MAX];
int top = -1;
void push(struct Node* node){
    if(top == MAX-1) return;
    stack[++top] = node;
    printf("Pushing done :)");
}
struct Node* pop(){
    if(top == -1) return NULL;
    struct Node* temp = stack[top--];
    printf("Popped :(");
    return temp;
}
void displayStack(){
    if(top == -1) return;
    for(int i=top; i>=0 ;i--){
        printf("%c ",stack[i]->data);
    }
    printf("\n");
}
struct Node* createNode(char data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void preorder(struct Node* root){
    if(root){
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct Node* buildTree(char postfix[]){
    for(int i=0; postfix[i] != '\0' ;i++){
        char ch = postfix[i];
        if(ch == ' ') continue;
        if(isalnum(ch)) push(createNode(ch));
        else{
            struct Node* node = createNode(ch);
            node->right = pop();
            node->left = pop();
            push(node);
        }
    }
    return pop();
}
void inorder(struct Node* root){
    if(root){
        if(!isalnum(root->data)) printf("(");
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
        if(!isalnum(root->data)) printf(")");
    }
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)\n");
    char postfix[100];
    struct Node* root = NULL;
    int choice;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display Stack\n4.Build Tree\n5.Inorder\n6.Preorder\n7.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char ch;
                printf("Enter data: ");
                scanf(" %c", &ch);
                push(createNode(ch));
                break;
            }
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4:
                printf("Enter postfix: ");
                scanf(" %[^\n]", postfix);
                root = buildTree(postfix);
                printf("Tree built successfully.\n");
                break;
            case 5:
                printf("Infix: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Prefix: ");
                preorder(root);
                printf("\n");
                break;
            case 7: return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
