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

struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* queue[100];
int front = 0, rear = 0;
void enqueue(struct Node* n){
    queue[rear++] = n;
}
struct Node* dequeue(){
    return queue[front++];
}
int isEmpty(){
    return front == rear;
}
struct Node* insertLevelOrder(struct Node* root, int val){
    struct Node* newNode = createNode(val);
    if(root == NULL) return newNode;
    front = rear = 0;
    enqueue(root);
    while(!isEmpty()){
        struct Node* temp = dequeue();
        if(temp->left == NULL){
            temp->left = newNode;
            return root;
        }else{
            enqueue(temp->left);
        }
        if(temp->right == NULL){
            temp->right = newNode;
            return root;
        }else{
            enqueue(root->right);
        }
    }
    return root;
}
int count = 0;
struct Node* insertAtSpecificPos(struct Node* root , int val, int level, int pos){
    if (!root) return NULL;
    if (level == 1) {
        count++;
        if (count == pos) {
            struct Node* newNode = createNode(val);
            if (!root->left) newNode->left = root;
            else newNode->right = root;
            return newNode;
        }
        return root;
    }
    root->left = insertAtPos(root->left, val, level - 1, pos);
    root->right = insertAtPos(root->right, val, level - 1, pos);
    return root;
}
void printLevel(Struct Node* root , int lvl){
    if(root == NULL) return;
    if(lvl == 1){
        printf("%d",root->data);
        return;
    }
    printLevel(root->left,lvl-1);
    printLevel(root->right,lvl-1);
}
// to print the nodes of the deepest lvl --> printLevel(root,height(root));
int height(Struct Node* root){
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l>r?l:r)+1;
}

// Traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void inorderIterative(struct Node* root){
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}
void preorderIterative(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right)
            stack[++top] = curr->right;
        if (curr->left)
            stack[++top] = curr->left;
    }
}
void postorderIterative(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left)
            stack1[++top1] = curr->left;
        if (curr->right)
            stack1[++top1] = curr->right;
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

// function to Mirror/Reverse the Tree
void mirror(struct Node* root){
    if(root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
// Finding Min/Max in a Tree
int findMin(struct Node* root){
    if(root == NULL) return INT_MAX;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    int min = root->data;
    if(leftMin < min) min = leftMin;
    if(rightMin < min) min = rightMin;
    return min;
}
int findMax(struct Node* root){
    if(root == NULL) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int Max = root->data;
    if(leftMax > Max) Max = leftMax;
    if(rightMax > Max) Max = rightMax;
    return Max;
}
// Level order Display
void levelOrderDisplay(struct Node* root){
    if(root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(!isEmpty()){
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if(temp->left) queue[rear++] = temp->left;
        if(temp->right) queue[rear++] temp->right;
    }
}
// Copying tree into another
struct Node* copyTree(struct Node* root){
    if(root == NULL) return NULL;
    struct Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}
// Checking if two Trees are identical --> aa sakta hai!!! karle bsdk
int isIdentical(struct Node* t1 , struct Node* t2){
    if(t1 == NULL && t2 == NULL) return 1;  
    if( t1 == NULL || t2 == NULL) return 0; // identical nhi rahe
    return t1->data == t2->data && isIdentical(t1->left,t2->left) && isIdentical(t1->right,t2->right);
    // in case of symmetry , change last return statement too : 
   // t1->data == t2->data && isIdentical(t1->left,t2->right) && isIdentical(t1->right,t2->left);
}
// Printing Ancestors of a given node
int printAncestors(struct Node* root , int target){
    if(root == NULL) return 0;
    if(root->data == target) return 1;
    if(printAncestors(root->left,target) || printAncestors(root->right,target)){
        printf("%d ",root->data);
        return 1;
    }
    return 0; // fallback
}
// Sub Variation -> Lowest Common Ancestor -> Find the first root where the path diverges ( left and right) between nodes p and q 
struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q ){
    if(root == NULL) return NULL;
    int curr = root->val;
    if(curr < p->val && curr > q->val) return lowestCommonAncestor(root->right,p,q);
    if(curr > p->val && curr < q->val) return lowestCommonAncestor(root->left,p,q);
    return root;
}
// Sum of All Nodes/Leaf Nodes
int sumAll(struct Node* root){
    if(root == NULL) return 0;
    return root->data + sumAll(root->left) + sumAll(root->right);
}
int sumLeaf(struct Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    return sumLeaf(root->left) + sumLeaf(root->right);
}
// Sum of Nodes at a given Level -> possibility hai
int sumAtLevel(struct Node* root, int level){
    if(root == NULL) return 0;
    if(level == 1) return root->data;
    return sumAtLevel(root->left,level-1) + sumAtLevel(root->right,level-1);
}
// Count Nodes Greater than X 
int countGreater(struct Node* root, int x){
    if(root == NULL) return 0;
    int count = root-data > x ? 1:0;
    return countGreater(root->left,x) + countGreater(root->right,x);
}
// Path Sum - LC Path Sum 1 
int hasPathSum(struct Node* root,int sum){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data == sum ; // leaf pe aagye
    return hasPathSum(root->left , sum - root->data) || hasPathSum(root->right, sum- root->data);
}
// LC : Path Sum 2 
int pathSum2(struct Node* root, int sum){ // Find all root-leaf paths where the sum == Target
    int path[100]; // this is why I hate C
    pathSum2Finder(root,sum,path,0);
}
void pathSum2Finder(struct Node* root, int sum , int path[], int pathLen){
    if(root == NULL) return;
    path[pathLen] = root->data;
    pathLen++;
    // Leaf node pe aao
    if(root->left == NULL  && root->right == NULL && sum == root->data){
        printPath(path,pathLen);
    }else{ // Fallback
        pathSum2Finder(root->left , sum - root->data, path, pathLen);
        pathSum2Finder(root->right, sum - root->data, path, pathLen);
    }
}
void printPath(int path[], int pathLen) {
    for(int i=0; i<pathLen; i++)
        printf("%d ", path[i]);
    printf("\n");
}
// Left / Right Side view of a Tree
void leftView(struct Node* root){
    if(root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        int level = rear - front;
        for(int i=0; i< level; i++){
         struct Node* temp = queue[front++];
         if(i==0) printf("%d ",temp->data);
         if(temp->left) queue[rear++] =  temp->left;
         if(temp->right) queue[rear++] = temp->right
        }
    }
}
void rightView(struct Node* root){
    if(root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        int level = rear - front;
        for(int i=0; i< level; i++){
         struct Node* temp = queue[front++];
         if(i==level-1) printf("%d ",temp->data);
         if(temp->left) queue[rear++] =  temp->left;
         if(temp->right) queue[rear++] = temp->right;
        }
    }
}
int main(){
    // Insert your example inputs here to test this program
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
