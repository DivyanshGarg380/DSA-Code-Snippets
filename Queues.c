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


int main(){
    // Insert your example inputs here to test this program
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
// Code shared for reference only. Unauthorized use or submission under my Username - Starman248 is prohibited.
