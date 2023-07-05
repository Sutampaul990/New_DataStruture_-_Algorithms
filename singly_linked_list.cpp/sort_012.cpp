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

Node* sorting(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp!=NULL){
        if(temp->data==0)
            zeroCount++;
        else if(temp->data == 1)
            oneCount++;
        else
            twoCount++;
        temp=temp->next;
    }

    temp = head;

    while(temp!=NULL)
    {
        if(zeroCount!=0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount!=0)
        {
            temp->data = 1;
            oneCount--;
        }
        else
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(0);
    Node* node3 = new Node(0);
    Node* node4 = new Node(2);
    Node* node5 = new Node(1);
    Node* node6 = new Node(2);

    Node* head = node1;
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    cout<<"After sorting 0,1,2 : ";
    head = sorting(head);
    print(head);

    return 0;
}