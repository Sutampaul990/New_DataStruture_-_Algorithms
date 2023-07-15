#include<bits/stdc++.h>

using namespace std;

void sortedStack(stack<int> &stack, int num)
{
	if(stack.empty() || num>stack.top())
	{
		stack.push(num);
		return;
	}
	int n = stack.top();
	stack.pop();

	sortedStack(stack,num);
	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
        return;
    
    int num = stack.top();
    stack.pop();

    sortStack(stack);

	sortedStack(stack,num);
}

int main()
{
    int arr[5];
    stack<int>st;

    cout<<"Enter any number : ";

    for(int i=0;i<5;i++){
        cin>>arr[i];
        st.push(arr[i]);
    }
    

    sortStack(st);

    cout<<"After insertion : "<<endl;
    while(!st.empty())
    {
        cout<<st.top();
        cout<<"\t";
        st.pop();
    }

    return 0;
}