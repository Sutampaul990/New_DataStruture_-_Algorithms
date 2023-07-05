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

void insertAtEnd(Node* &head,Node* cur)
{
    head->next = cur;
    head = cur;
}

Node* sorting(Node* head)
{
    if(head == NULL || head->next==NULL)
        return head;
    
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* temp = head;

    while(temp!=NULL)
    {
        int value = temp->data;

        if(value==0)
            insertAtEnd(zeroTail,temp);

        else if(value==1)
            insertAtEnd(oneTail,temp);

        else
            insertAtEnd(twoTail,temp);
        
        temp = temp->next;
    }

    // Merging 3 list

    if(oneHead->next!=NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    //Delete Dummy Nodes

    delete oneHead;
    delete zeroHead;
    delete twoHead;

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