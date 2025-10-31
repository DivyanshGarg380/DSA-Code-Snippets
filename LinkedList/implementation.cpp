#include<iostream>
using namespace std;
struct node{
int data;
node* next;
node(int val){
 data=val;
 next=nullptr;
}
};
class list{
private:
node* head;
public:
list(){
head=nullptr;
}
void addatbeginning(int val){
node* newnode=new node(val);
newnode->next=head;
head=newnode;
}
void addatend(int val){
node* newnode=new node(val);
if(head==nullptr){
head=newnode;
return;
}
node* temp=head;
while(temp->next!=nullptr){
temp=temp->next;
}
temp->next=newnode;
}
void editelement(int oldval,int newval){
node* temp=head;
while(temp!=nullptr){
    if(temp->data==oldval){
     temp->data=newval;
     cout<<"element "<<oldval<<" updated to "<<newval<<endl;
     return;
    }
    temp=temp->next;
    }
    cout<<"element"<<oldval<<"not found\n";
    }
    void deleteelement(int val){
        if(head==nullptr){
        cout << "List is empty, nothing to delete!" << endl;
        return;
        }
        if(head->data==val){
        node* temp=head;
        head=head->next;
        delete temp;
        cout<<"element "<<val<<" deleted!"<<endl;
        return;
        }
        node* temp=head;
        while(temp->next !=nullptr){
        if(temp->next->data==val){
        node* toDelete= temp->next;
        temp->next= temp->next->next;
        delete toDelete;
        cout<<"element "<<val<<" deleted!"<<endl;
        return;
        }
        temp=temp->next;
        }
        cout<<"element "<<val<<" not found!"<<endl;
        }
        
    int searchelement(int val){
    node* temp=head;
    int position=1;
    while(temp!=nullptr){
    if(temp->data==val){
    return position;
    }
    temp=temp->next;
    position++;
    }
    return -1;
}
    void display(){
    if(head==nullptr){
    cout<<"list is empty!"<<endl;
    return;
    }
    node* temp=head;
    while(temp!=nullptr){
    cout<<temp->data<<"->";
    temp=temp->next;
    }
    cout<<"nullptr"<<endl;
    }
    };
    int main(){
       list l;
       l.addatbeginning(9);
       l.addatend(30);
       l.addatend(60);
       l.addatbeginning(8);
       cout<<"current list : ";
       l.display();
       l.editelement(30,25);
       cout<<"list after editing : ";
       l.display();
       int position= l.searchelement(8);
       if(position!=-1){
       cout<<"element found at position : "<<position<<endl;
       }
       else{
       cout<<"element not found"<<endl;
       }
       l.deleteelement(100);
       l.deleteelement(60);
       

    cout<<"final list : ";
    l.display();
    return 0;
     }
    