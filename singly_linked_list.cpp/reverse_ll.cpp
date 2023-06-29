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

//Another way
Node* recursive(Node* head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node* min_head = recursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return min_head;
}

// Recursive Way
Node* reverseR(Node* &head,Node* cur,Node* prev)
{
    if(cur==NULL)
    {
        head = prev;
        return head;
    }
    reverseR(head,cur->next,cur);
    cur->next = prev;
}

//Iterative Way
Node* reverseLL(Node* head)
{
    Node* prev = NULL;
    Node* cur = head;
    reverseR(head,cur,prev);
    return head;
    /*
    Node* prev = NULL;
    Node* forward = NULL;
    Node* cur = head;
    while(cur!=NULL)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    */
    
    //return prev;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    Node* head = node1;
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    cout<<"Here the Reverse : ";
    
    head = recursive(head);
    print(head);

    return 0;
}