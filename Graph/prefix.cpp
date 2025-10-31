#include<iostream>
#include<string>
using namespace std;

#define capacity 10

class stack{
public:
int arr[capacity];
int top;

stack()
{
top= -1;
}
bool isempty()
{
return top== -1;
}
bool isfull()
{
return top== capacity-1;
}

void push(int value)
{
if (isfull())
{
cout<<"stack overflow." <<endl;
}
else
{
arr[++top] = value;
cout<< value <<"pushed onto stack." <<endl;
}
}
int pop()
{
if (isempty())
{
cout<<"stack underflow." <<endl;
return -1;
}
else
{
int val = arr[top--];
return val;
}
}
};

int prefix(string exp)
{
stack stk;
for(int i = exp.length()-1; i>=0 ; i--)
{
char a = exp[i];
if(a>='0' && a<='9')
{
stk.push(a - '0');
}
else
{
int b = stk.pop();
int c = stk.pop();
int result = 0;

if ( a == '+')
{
result = b + c;
}
if ( a == '-')
{
result = c - b;
}
if ( a == '*')
{
result = b * c;
}
if ( a == '/')
{
result = c/b ;
} 
stk.push(result);
}
}
return stk.pop();
}
int main()
{
string pref;
cout<<" enter the prefix expression:" <<endl;
cin >> pref;
cout<<" result= " << prefix(pref) <<endl;
return 0;
}