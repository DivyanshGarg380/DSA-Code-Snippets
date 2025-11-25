/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/

#include <stdio.h>
#include <stdlib.h>
struct Node{
    int key;
    struct Node* left, *right;
    int height;
};
int height(struct Node* n){
    if(n == NULL) return 0;
    return n->height;
}
int max(int a, int b){
    return a > b ? a : b;
}
struct Node* createNode(int key){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
struct Node* LL(struct Node* y){
    struct Node* x = y->left;
    struct Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;
    return x;
}
struct Node* RR(struct Node* x){
    struct Node* y = x->right;
    struct Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
int balance(struct Node* n){
    if(n==NULL) return 0;
    return height(n->left)-height(n->right);
}
struct Node* insert(struct Node* node, int key){
    if(node == NULL) return createNode(key);
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right,key);
    else return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balanceFac = balance(node);
    if(balanceFac > 1 && key < node->left->key) return LL(node);
    if(balanceFac < -1 && key > node->right->key) return RR(node);
    if(balanceFac > 1 && key > node->left->key){
        node->left = RR(node->left);
        return LL(node);
    }
    if(balanceFac < -1 && key < node->right->key){
        node->right = LL(node->right);
        return RR(node);
    }
    return node;
}
struct Node* minVal(struct Node* node){
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}
struct Node* deleteNode(struct Node* root, int key){
    if(root == NULL) return root;
    if(key < root->key) root->left = deleteNode(root->left, key);
    else if(key > root->key) root->right = deleteNode(root->right,key);
    else{ // destination reached
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }else{
            struct Node* temp = minVal(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }
    if(root == NULL) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFac = balance(root);
    if(balanceFac > 1 && key < root->left->key) return LL(root);
    if(balanceFac < -1 && key > root->right->key) return RR(root);
    if(balanceFac > 1 && key > root->left->key){
        root->left = RR(root->left);
        return LL(root);
    }
    if(balanceFac < -1 && key < root->right->key){
        root->right = LL(root->right);
        return RR(root);
    }
    return root;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf(" %d ", root->key);
        inorder(root->right);
    }
}
int main(){
    // Insert your example inputs here to test this program
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
