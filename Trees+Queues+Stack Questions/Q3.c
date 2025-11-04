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
Question: Create a doubly linked list (DLL) of n nodes with the following operations:
Delete the nth node from the end.
Create another DLL and append it to the updated first DLL.
Delete duplicate nodes.
Display the list.
Convert the DLL into a binary search tree (BST).
*/
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
    int data;
    struct Node* prev,*next;
};
struct BST{
    int data;
    struct BST* left, *right;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
void append(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
         return;
    }
    struct Node* temp = *head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void display(struct Node* head){
    struct Node* temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteEnd(struct Node** head, int n){
    if(*head == NULL) return;
    struct Node* first = *head;
    struct Node* second = *head;
    for(int i=0; i<n;i++){
        if(first == NULL) return; // length exceed kargaya :(
        first = first->next;
    }
    if(first == NULL){ // delete head cause pointer reached the end lol :()
        struct Node* del = *head;
        *head = (*head)->next;
        if(*head) (*head)->prev = NULL;
        free(del);
        return;
    }
    while(first->next){
        first = first->next;
        second = second->next;
    }
    struct Node* del = second->next;
    second->next = del->next;
    if(del->next) del->next->prev = second;
    free(del);
}
void appendDLL(struct Node** head1, struct Node* head2){
    if(*head1 == NULL){
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while(temp->next) temp = temp->next;
    temp->next = head2;
    if(head2) head2->prev = temp; 
}
void deleteDuplicates(struct Node* head){
    bool seen[15] = {false};
    struct Node* curr = head;
    struct Node* dup;
    while(curr != NULL){
        if(seen[curr->data]){ // duplicate found bc
            dup = curr;
            curr = curr->next;
            if(dup->prev){
                dup->prev->next = dup->next;
            }if(dup->next){
                dup->next->prev = dup->prev;
            }
            free(dup);
        }else{
            seen[curr->data] = true;
            curr = curr->next;
        }
    }
}
int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}
void inorderBST(struct BST* root) {
    if (root) {
        inorderBST(root->left);
        printf("%d ", root->data);
        inorderBST(root->right);
    }
}
struct Node* getMiddle(struct Node** head){
    struct Node* slow = *head;
    struct Node* fast = *head;
    if(!*head) return NULL;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        if(fast) slow = slow->next;
    }// slow is pointing to middle now lol
    return slow;
}
struct BST* convertBST(struct Node* head){
    if(!head) return NULL;
    if (!head) return NULL;
    if (!head->next) { 
        struct BST* root = (struct BST*)malloc(sizeof(struct BST));
        root->data = head->data;
        root->left = root->right = NULL;
        return root;
    }
    struct Node* mid = getMiddle(&head);
    struct BST* root = (struct BST*)malloc(sizeof(struct BST));
    root->data = mid->data;
    root->left = root->right = NULL;
    struct Node* leftHead = head;
    struct Node* rightHead = mid->next;
    if (mid->prev) mid->prev->next = NULL;
    if (mid->next) mid->next->prev = NULL;
    root->left = convertBST(leftHead == mid ? NULL : leftHead);
    root->right = convertBST(rightHead);

    return root;
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct BST* root = NULL;

    int n, m, data, choice, k;

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Create DLL 1\n");
        printf("2. Delete nth node from end\n");
        printf("3. Create DLL 2 and append\n");
        printf("4. Delete duplicates\n");
        printf("5. Display DLL\n");
        printf("6. Convert DLL to BST (Inorder Display)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    append(&head1, data);
                }
                break;

            case 2:
                printf("Enter n: ");
                scanf("%d", &k);
                deleteEnd(&head1, k);
                break;

            case 3:
                printf("Enter number of nodes for DLL 2: ");
                scanf("%d", &m);
                for (int i = 0; i < m; i++) {
                    scanf("%d", &data);
                    append(&head2, data);
                }
                appendDLL(&head1, head2);
                printf("DLLs appended successfully.\n");
                break;

            case 4:
                deleteDuplicates(head1);
                printf("Duplicates deleted.\n");
                break;

            case 5:
                display(head1);
                break;

            case 6:
                root = convertBST(head1);
                printf("BST (Inorder): ");
                inorderBST(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
