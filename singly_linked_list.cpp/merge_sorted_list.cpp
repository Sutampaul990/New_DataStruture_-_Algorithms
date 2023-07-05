#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<endl;
}
Node* solve(Node* first, Node* second)
{

    if(first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node* cur1 = first;
    Node* next1 = cur1->next;
    Node* cur2 = second;
    Node* next2 = cur2->next;

    while(next1!=NULL && cur2!=NULL)
    {
        if((cur2->data >= cur1->data)&&(cur2->data <= next1->data))
        {
            //Insert the Node
            cur1->next = cur2;
            next2 = cur2->next;
            cur2->next = next1;
           

            // Upgrade
            cur1 = cur2;
            cur2 = next2;
        }
        else
        {
            cur1 = next1;
            next1 = next1->next;
        }
        if(next1==NULL)
        {
            cur1->next = cur2;
            return first;
        }
    }
    return first;
}


Node* sortTwoLists(Node* first, Node* second)
{
    // Write your code here.
    if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    if(first->data <= second->data)
        return solve(first,second);

    else
        return solve(second,first);
}

int main()
{
    Node* first = new Node(1);
    Node* node1 = new Node(3);
    Node* node2 = new Node(5);

    first->next = node1;
    node1->next = node2;
    node2->next = NULL;

    Node* second = new Node(2);
    Node* node3 = new Node(4);
    Node* node4 = new Node(5);

    second->next = node3;
    node3->next = node4;
    node4->next = NULL;

    cout<<"First List : ";
    print(first);
    cout<<"\nSecond List : ";
    print(second);

    cout<<"\nMerge two sorted list : ";
    first = sortTwoLists(first,second);
    print(first);
    
    return 0;
}