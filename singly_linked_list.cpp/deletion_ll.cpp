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

void deleteatBegin(Node* &head)
{
    head = head->next;
}

void deleteatEnd(Node* &head)
{
    Node* temp = head;
    while(temp->next->next!=NULL)
        temp = temp->next;
    
    temp->next = NULL;
}

void deleteatPos(Node* &head,int pos)
{
    Node* temp = head;
    if(pos==1)
    {
        deleteatBegin(head);
        return;
    }
    int i=1;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
}

int main()
{
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);
    cout<<"At the Starting Head of the LL : \n";
    Node* head = node1;
    print(head);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    // cout<<"\nDelete op at beginning : \n";
    // deleteatBegin(head);
    // print(head);

    // cout<<"\nDelete op at End : \n";
    // deleteatEnd(head);
    // print(head);

    cout<<"\n Delete at desired position : \n";
    deleteatPos(head,2);
    print(head);


    return 0;
}