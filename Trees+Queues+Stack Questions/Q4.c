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
Question: Create a menu-driven program to replicate a hotel management system with the following functionalities:
Insert a new guest while checking in, and delete that guest from the records after checking out
Maintain a separate record for the latest check-in and latest check-out of a guest
Hotel admin can create a new record of a guest and even delete it. A function to display all guests that visited the hotel, 
another to display all checked-in guests, and another one to display all checked-out guests.
*/
// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Guest{
    int id;
    char name[50];
    struct Guest* prev, *next;
};
struct Guest* checkedIn = NULL;
struct Guest* checkedOut = NULL;
struct Guest* allGuests = NULL;
struct Guest* latestCheckIn = NULL;
struct Guest* latestCheckOut = NULL;
struct Guest* createGuest(int id, char name[]){
    struct Guest* newGuest = (struct Guest*)malloc(sizeof(struct Guest));
    newGuest->id = id;
    strcpy(newGuest->name,name);
    newGuest->prev = newGuest->next = NULL;
    return newGuest;
}
void append(struct Guest** head, struct Guest* newGuest){
    if(*head == NULL){
        *head = newGuest;
        return;
    }
    struct Guest* temp = *head;
    while(temp->next) temp = temp->next;
    temp->next = newGuest;
    newGuest->prev = temp;
}
struct Guest* deleteGuest(struct Guest** head, int id){
    struct Guest* temp = *head;
    while(temp){
        if(temp->id == id){
            if(temp->prev) temp->prev->next = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
            temp->prev = temp->next = NULL;
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void displayList(struct Guest* head) {
    if (!head) {
        printf("Kaun hai ye.\n");
        return;
    }
    while (head) {
        printf("ID: %d Name: %s\n", head->id, head->name);
        head = head->next;
    }
}
void checkIn(){
    int id;
    char name[50];
    printf("Enter Guest ID: ");
    scanf("%d",&id);
    printf("Enter Guest's name: ");
    scanf("%s",name);
    struct Guest* newGuest = createGuest(id,name);
    append(&checkedIn,newGuest);
    append(&allGuests,newGuest);
    latestCheckIn = newGuest;
    printf("Check In Done :)");
}
void checkOut(){
    int id;
    printf("Enter ID to checkout: ");
    scanf("%d",&id);
    struct Guest* guest = deleteGuest(&checkedIn,id);
    if(!guest){
        printf("Kaun hai ye ");
        return;
    }
    append(&checkedOut,guest);
    latestCheckOut = guest;
    printf("Check out done :(");
}
void showLatest(){
     printf("\n--- Latest Records ---\n");
    if (latestCheckIn)
        printf("Latest Check-In: %s (ID: %d)\n", latestCheckIn->name, latestCheckIn->id);
    else
        printf("No check-ins yet.\n");

    if (latestCheckOut)
        printf("Latest Check-Out: %s (ID: %d)\n", latestCheckOut->name, latestCheckOut->id);
    else
        printf("No check-outs yet.\n");
}
int main() {
    // Write C code here
    printf("Divyansh Garg :)");
    int choice;
    while (1) {
        printf("\n------ HOTEL MANAGEMENT MENU ------\n");
        printf("1. Check-In Guest\n");
        printf("2. Check-Out Guest\n");
        printf("3. Display Checked-In Guests\n");
        printf("4. Display Checked-Out Guests\n");
        printf("5. Display All Guests\n");
        printf("6. Show Latest Check-In/Out\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkIn(); break;
            case 2: checkOut(); break;
            case 3: 
                printf("\n--- Checked-In Guests ---\n");
                displayList(checkedIn);
                break;
            case 4:
                printf("\n--- Checked-Out Guests ---\n");
                displayList(checkedOut);
                break;
            case 5:
                printf("\n--- All Guests ---\n");
                displayList(allGuests);
                break;
            case 6:
                showLatest();
                break;
            case 7:
                printf("Exiting Hotel System...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
