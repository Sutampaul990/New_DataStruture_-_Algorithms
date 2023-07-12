// Basically it is used by STL ....
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int>s;

    s.push(2);
    s.push(3);

    s.pop();

    cout<<"Print the top Element : "<<s.top()<<endl;

    if(s.empty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
    cout<<"Size of the Stack : "<<s.size()<<endl;
    return 0;
}