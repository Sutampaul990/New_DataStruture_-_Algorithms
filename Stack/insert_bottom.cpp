#include<bits/stdc++.h>

using namespace std;

/*stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    stack<int> temp;

    while(!myStack.empty())
    {
        temp.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);

    while(!temp.empty())
    {
        myStack.push(temp.top());
        temp.pop();
    }
    return myStack;
}*/

// Recursion

void solve(stack<int>& myStack, int x)
{
    if(myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();

    solve(myStack,x);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x)
{
    // Write your code here.
    
    solve(myStack,x);
    return myStack;
}

int main()
{
    int arr[5];
    stack<int>st;

    cout<<"Enter any number : ";

    for(int i=0;i<4;i++){
        cin>>arr[i];
        st.push(arr[i]);
    }
    


    int x;
    cout<<"Enter a number want to insert at bottom : ";
    cin>>x;
    st = pushAtBottom(st,x);

    cout<<"After insertion : "<<endl;
    while(!st.empty())
    {
        cout<<st.top();
        cout<<"\t";
        st.pop();
    }

    return 0;
}