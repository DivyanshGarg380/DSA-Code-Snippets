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
1) Question: Implement a doubly linked list (DLL) with the following functionalities: 
Read and display the list. Create a second list, separate even and odd numbers, and sort them. 
Read a third list and perform a union operation with the sorted list. Delete alternate nodes in the list.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next , *prev;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
// append last mein
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
// display func
void display(struct Node* head){
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// deleting alternate
void deleteAlternate(struct Node** head){
    if(*head == NULL) return;
    struct Node* temp = *head;
    while(temp && temp->next){
        struct Node* del = temp->next;
        temp->next = del->next;
        if(del->next) del->next->prev = temp;
        free(del);
        temp = temp->next;
    }
}
// sroting DLL
void sortDLL(struct Node* head){
    if(!head) return;
    struct Node* i, *j;
    for(i = head; i->next != NULL; i = i->next){
        for(j=i->next; j!=NULL; j = j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void seperateEvenOdd(struct Node* head, struct Node** even, struct Node** odd){
    if(!head) return;
    struct Node* temp = head;
    while(temp){
        if(temp->data % 2 == 0) append(even,temp->data);
        else append(odd,temp->data);
        temp = temp->next;
    }
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
