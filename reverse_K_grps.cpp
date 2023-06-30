#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node * next;

    //Constructor
    Node(int data){
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

Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head==NULL)
    return NULL;

    Node* forward = NULL;
    Node* prev = NULL;
    Node* cur = head;
    int count = 0;
    int c=0;

    while(cur != NULL) {
        c++;
        cur = cur->next;
    }

    cur = head;

    while(cur!=NULL && count<k)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
        count++;
        c--; 
    }

    if(forward!=NULL && c>=k)
        head->next = kReverse(forward, k);
    else
        head->next = forward;

    return prev;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    Node* node5 = new Node(50);
    Node* node6 = new Node(60);

    Node* head = node1;
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    cout<<"After reversing in k groups : ";
    Node* y = kReverse(head,2);
    print(y);

    return 0;
}