#include<iostream>
using namespace std;

class Stack{
    //Properties
    public:
        int top;
        int *arr;
        int size;
    
    //Behavior
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top >1){
            top++;
            arr[top] = element;
            cout<<"Element has been pushed"<<endl;
        }
        else
        {
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop()
    {
        if(top>=0)
        {
            top--;
            cout<<"Element has been popped"<<endl;
        }
        else{
            cout<<"Stack is underflow"<<endl;
        }
    }
    int peek()
    {   if(top>=0)
            return arr[top];
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
};

int main()
{
    Stack st(5);

    st.push(22);
    st.push(10);
    st.push(18);

    cout<<"Top element of Stack : "<<st.peek()<<endl;

    st.pop();

    cout<<"Top element of Stack : "<<st.peek()<<endl;
    st.pop();

    cout<<"Top element of Stack : "<<st.peek()<<endl;
    st.pop();

    cout<<"Top element of Stack : "<<st.peek()<<endl;

    return 0;
}
