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
BST
1.Create and Display a BST
2.Find and display the second smallest no. in the BST
3.Delete the node with non empty left subtree and empty right subtree. 
4.Find the difference between the no. of nodes of the left subtree and the right subtree.
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
struct Node* insert(struct Node* root, int data){
    if(root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void secondSmallest(struct Node* root, int *count, int* result){
    if(root == NULL || *count >= 2) return;
    secondSmallest(root->left,count,result);
    (*count)++;
    if(*count == 2) *result = root->data;
    secondSmallest(root->right,count,result);
}
int countNodes(struct Node* root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
struct Node* deleteSpecial(struct Node* root){ // bakchodi hai ye sab
    if(root == NULL) return NULL;
    root->left = deleteSpecial(root->left);
    root->right = deleteSpecial(root->right);
    if(root->left != NULL && root->right == NULL){
        printf("Deleting node %d\n",root->data);
        struct Node* temp = root->left;
        free(root);
        return temp;
    }
    return root;
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
    struct Node* root = NULL;
    int choice, data;
    while (1) {
        printf("\n------ BST MENU ------\n");
        printf("1. Insert\n");
        printf("2. Display (Inorder)\n");
        printf("3. Find Second Smallest\n");
        printf("4. Delete Nodes (Left!=NULL, Right==NULL)\n");
        printf("5. Difference in Left & Right Subtree Nodes\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("BST Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3: {
                int count = 0, result = -1;
                secondSmallest(root, &count, &result);
                if (result != -1)
                    printf("Second smallest number: %d\n", result);
                else
                    printf("Not enough nodes in BST.\n");
                break;
            }

            case 4:
                root = deleteSpecial(root);
                printf("Updated BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;

            case 5: {
                if (root == NULL) {
                    printf("Tree empty.\n");
                    break;
                }
                int leftCount = countNodes(root->left);
                int rightCount = countNodes(root->right);
                printf("Left subtree nodes: %d\n", leftCount);
                printf("Right subtree nodes: %d\n", rightCount);
                printf("Difference = %d\n", abs(leftCount - rightCount));
                break;
            }

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
