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
Binary Tree
1.⁠ ⁠Iterative create bt
2.⁠ ⁠Display bt in tree form
3.⁠ ⁠Iterative pre order
4.⁠ ⁠Delete a node with less than degree 2 (User Input)
5.⁠ ⁠Display all non leaf nodes
*/
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left, *right;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* createTree(){
    int data;
    printf("Enter root value , -1 for NULL");
    scanf("%d",&data);
    if(data == -1) return NULL;
    struct Node* root = createNode(data);
    struct Node* queue[69];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        struct Node* curr = queue[front++];
        int leftData, rightData;
        printf("Enter left child of %d ",curr->data);
        scanf("%d",&leftData);
        if(leftData != -1){
            curr->left = createNode(leftData);
            queue[rear++] = curr->left;
        }
        printf("Enter right child of %d (-1 for NULL): ", curr->data);
        scanf("%d", &rightData);
        if (rightData != -1) {
            curr->right = createNode(rightData);
            queue[rear++] = curr->right;
        }
    }
    return root;
}
void displayTree(struct Node* root) {
    if (!root) {
        printf("Tree empty.\n");
        return;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    printf("\nBinary Tree (Level Order): ");
    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    printf("\n");
}
void iterativePreorder(struct Node* root){
    if(!root) return;
    struct Node* stack[69];
    int top = -1;
    stack[++top] = root;
    while(top >= 0){
        struct Node* curr = stack[top--];
        printf("%d ",curr->data);
        if(curr->right) stack[++top] = curr->right;
        if(curr->left) stack[++top] = curr->left;
    }
    printf("\n");
}
struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return NULL;
    root->left = deleteNode(root->left,key);
    root->right = deleteNode(root->right,key);
    if(root->data == key){
        int degree = 0;
        if(root->left) degree++;
        if(root->right) degree++;
        if(degree < 2){
            printf("Deleting %d degree\n", root->data);
            struct Node* child = root->left ? root->left : root->right;
            free(root);
            return child;
        }
    }
    return root;
}
void displayNonLeaf(struct Node* root){
    if(!root) return;
    if(root->left || root->right) printf("%d ",root->data);
    displayNonLeaf(root->left);
    displayNonLeaf(root->right);
} 
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\n------ BINARY TREE MENU ------\n");
        printf("1. Create Tree (Iterative)\n");
        printf("2. Display Tree (Level Order)\n");
        printf("3. Iterative Preorder Traversal\n");
        printf("4. Delete Node with Degree < 2\n");
        printf("5. Display Non-leaf Nodes\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                displayTree(root);
                break;
            case 3:
                iterativePreorder(root);
                break;
            case 4:
                printf("Enter node value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 5:
                printf("Non-leaf Nodes: ");
                displayNonLeaf(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
