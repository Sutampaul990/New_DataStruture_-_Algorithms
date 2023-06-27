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

void insertAthead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

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

void insertAttail(Node* &head,int data)
{
    Node* temp = head;
    Node* insert = new Node(data);
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = insert;
}

void insertAtpos(Node* &head,int data,int pos)
{
    Node* temp = head;
    Node* insert = new Node(data);
    if(pos==1)
    {
        insertAthead(head,data);
        return;
    }
    int i;
    for (int i=1;i<pos-1;i++)
    {
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;
}

int main()
{
    // Created a Node
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // head pointed Node

    cout<<"At the Starting Head of the LL : \n";
    Node* head = node1;
    print(head);

    cout<<"\nInsert at the Starting of the LL : \n";
    insertAthead(head,12);
    print(head);

    cout<<"\nInsert at the Starting of the LL : \n";
    insertAthead(head,15);
    print(head);

    cout<<"\nInsert at the End of LL : \n";
    insertAttail(head,20);
    print (head);

    cout<<"\nInsert At Desired position of the LL : \n";
    insertAtpos(head,8,1);
    print(head);

    return 0;
}