/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/
// Queues 

#include <stdio.h>
#include <stdlib.h>

// Remember -> In simple queue and other variations in it -> front = rear = -1
// in circular Queue -> front = rear = 0;
// thats why in enqueue function in 1st case we do ++rear 
// and in circular queue we do queue[rear] = item ; rear = (rear+1) % MAX_SIZE;
// No changes for deletion :)

// Conditions for Linear Queues, Multiple Queues ( Array of Queues - Linked Representation )
// 1) isEmpty() -> front == rear
// 2) isFull() -> rear == MAX_SIZE - 1

// Conditions for Circular Queues
// 1) isEmpty() -> front == rear
// 2) isFull() -> rear == (rear+1) % MAX_SIZE;

// Condition for deque 
// 1) isEmpty() -> front == -1
// 2) isFull() -> (front == 0 && rear == SIZE - 1) || (front == rear + 1)

// ---------------------DEQUE CODE-----------------------------------------
 # define SIZE 10
int deque[SIZE];
int front = -1, rear = -1;
int isFullDeque(){
    return ((front == 0 && rear == SIZE - 1 ) || (front == rear + 1));
}
int isEmptyDeque(){
    return (front == -1);
}
void insertFront(int x){
    if(isFullDeque()) return;
    if(isEmptyDeque()){
        front = rear = 0;
    }else if(front == 0){
        front = SIZE - 1;
    }else{
        front = front - 1;
    }
    deque[front] = x;
}
void insertRear(int x){
    if(isFullDeque()) return;
    if(isEmptyDeque()) front = rear = 0;
    else if(rear == SIZE - 1) rear = 0;
    else rear = rear + 1;
    deque[rear] = x;
}
void deleteFront(){
    if(isEmptyDeque()) return;
    printf("Deleted %d from front\n", deque[front]);
    if(front == rear) front = rear = -1;
    else if(front == SIZE -1) front = 0;
    else front = front + 1;
}
void deleteRear(){
    if(isEmptyDeque()) return;
    printf("Deleted %d from rear\n", deque[rear]);
    if(front == rear) front = rear = -1;
    else if(rear == 0) rear = SIZE - 1;
    else rear = rear - 1 ;
}
void printDeque(){
    if(isEmptyDeque()) return;
    int i = front;
    while(1){
        printf("%d ", deque[i]);
        if(i==rear) break;
        i = (i+1)%SIZE;
    }
}
// ---------------------PRIORITY CODE-----------------------------------------
int pq[SIZE];
int front = -1, rear = -1;
int isFullPQ(){
    return rear == SIZE - 1;
}
int isEmptyPQ(){
    return front == -1;
}
void insertPQ(int x){
    if(isFullPQ()) return;
    if(isEmptyPQ()){
        front = rear = 0;
        pq[rear] = x;
    }else{
        int i;
        for( i=rear; i>= front && pq[i] > x;i--){
            pq[i+1] = pq[i];
        }
        pq[i+1] = x;
        rear++;
    }
}
void deletePQ(){
    if(isEmptyPQ()) return;
    printf("Deleted %d\n", pq[front]);
    if(front == rear) front = rear = -1;
    else front++;
}
void displayPQ() {
    if (isEmptyPQ()) return;
    for (int i = front; i <= rear; i++)
        printf("%d ", pq[i]);
    printf("\n");
}
int main(){
    // Insert your example inputs here to test this program
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
