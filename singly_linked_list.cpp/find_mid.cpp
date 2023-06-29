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

// My Approach
/*
int length(Node* head)
{
    int len =0;
    while(head!=NULL){
        head= head->next;
        len++;
    }
    return len;
}

Node* current(Node* &head,int mid)
{
    Node* temp = head;
    int i=0;
    while(i<mid-1)
    {
        temp = temp->next;
        i++;
    } 
    head = temp;
    return head;
}

Node *findMiddle(Node *head) {
    // Write your code here
    int y = length(head);
    int mid = (y/2)+1;
    
    return current(head,mid);
}
*/

Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL || head->next == NULL)
    return head;
    else if(head->next->next == NULL)
    return head->next;

    Node* fast = head->next;
    Node* slow = head;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        slow = slow->next;

    }
    return slow;
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

    cout<<"Printing after middle of the list : ";
    Node* temp = findMiddle(head);
    print(temp);

    

    return 0;
}