#include <iostream>
using namespace std;
class stk{
   private: 
   int n = 10;
   int arr[10];
   int top;
   int i;
   
   public:
    stk(){
     top= -1;
     }
     void push(int k){
        if (isFull()) {
         cout<<"Error! Stack overflow!"<<endl;
         return;
         }
         else{
         cout<<"stack is not full"<<endl;
         }
         arr[++top]=k;
         cout<<"value pushed into stack ="<<k<<endl;
         
        }
        int pop(){
          if(isEmpty()){
           cout<<"Error! Stack underflow!<<endl";
           return -1;
           }
           else{
           cout<<"stack is not empty"<<endl;
           } 
           cout << "Popped value: " << arr[top] << endl;
            return arr[top--];
            }
        int peek(){
        if(isEmpty()){
           cout<<"Error! Stack underflow!"<<endl;
           return -1;
           }
           cout << "Top element is: " << arr[top] << endl;
           return arr[top];
           }
           
           
        bool isEmpty(){
           return top==-1;
           }
         bool isFull(){
           return top== n-1;
           }
           
         int Display(){
         if(isEmpty()){
           cout<<"Error! Stack underflow!"<<endl;
           return -1;
           }
          cout<<"Display all elements from tp to bottom"<<endl;
          for( i=top;i>=0;i--)
          {
            cout<<arr[i]<<endl;
           }
        }

        void search(int key) {
        if (isEmpty()) {
            cout << "Error! Stack is empty!" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            if (arr[i] == key) {
                cout << "Value " << key << " found at position " << (top - i + 1) << " from the top." << endl;
                return;
            }
        }
        cout << "Value " << key << " not found in stack." << endl;
    }
};
        
           
           
        int main() {
    stk s;
    int choice, k;

    while (true) {
        cout << "\n Menu:";
        cout << "\n 1. Push";
        cout << "\n 2. Pop";
        cout << "\n 3. Peek";
        cout << "\n 4. isEmpty";
        cout << "\n 5. isFull";
        cout << "\n 6. Display";
        cout << "\n 7. Search";
        cout << "\n 8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value: ";
            cin >> k;
            s.push(k);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
            break;
        case 5:
            cout << (s.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
            break;
        case 6:
            s.Display();
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> k;
            s.search(k);
            break;
        case 8:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
