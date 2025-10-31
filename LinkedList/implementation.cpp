#include <iostream>
using namespace std;

// Define a node structure for the linked list
struct node {
    int data;      // Data stored in the node
    node* next;    // Pointer to the next node

    // Constructor to initialize a node with a given value
    node(int val) {
        data = val;
        next = nullptr;
    }
};

// Class to represent a singly linked list
class list {
private:
    node* head; // Pointer to the first node of the list

public:
    // Constructor initializes an empty list
    list() {
        head = nullptr;
    }

    // Function to add a new node at the beginning of the list
    void addatbeginning(int val) {
        node* newnode = new node(val); // Create a new node
        newnode->next = head;          // Link new node to current head
        head = newnode;                // Update head to new node
    }

    // Function to add a new node at the end of the list
    void addatend(int val) {
        node* newnode = new node(val);
        if (head == nullptr) { // If list is empty
            head = newnode;
            return;
        }

        // Traverse till the last node
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newnode; // Link new node at the end
    }

    // Function to edit an existing element
    void editelement(int oldval, int newval) {
        node* temp = head;

        // Traverse and search for the old value
        while (temp != nullptr) {
            if (temp->data == oldval) {
                temp->data = newval;
                cout << "Element " << oldval << " updated to " << newval << endl;
                return;
            }
            temp = temp->next;
        }

        // If element not found
        cout << "Element " << oldval << " not found!" << endl;
    }

    // Function to delete a node by its value
    void deleteelement(int val) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }

        // If node to delete is the first node
        if (head->data == val) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element " << val << " deleted!" << endl;
            return;
        }

        // Search for the node to delete
        node* temp = head;
        while (temp->next != nullptr) {
            if (temp->next->data == val) {
                node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Element " << val << " deleted!" << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Element " << val << " not found!" << endl;
    }

    // Function to search an element and return its position
    int searchelement(int val) {
        node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == val) {
                return position;
            }
            temp = temp->next;
            position++;
        }

        return -1; // If not found
    }

    // Function to display the entire linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

// Main function to test all operations
int main() {
    list l;

    // Adding elements at beginning and end
    l.addatbeginning(9);
    l.addatend(30);
    l.addatend(60);
    l.addatbeginning(8);

    cout << "Current list: ";
    l.display();

    // Edit an element in the list
    l.editelement(30, 25);
    cout << "List after editing: ";
    l.display();

    // Search for an element
    int position = l.searchelement(8);
    if (position != -1) {
        cout << "Element found at position: " << position << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    // Delete operations
    l.deleteelement(100); // Not present
    l.deleteelement(60);  // Present

    cout << "Final list: ";
    l.display();

    return 0;
}
