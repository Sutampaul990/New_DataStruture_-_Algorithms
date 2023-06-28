#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len; 
}

void insertionHead(Node* &head,int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd(Node* &head,int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        return;
    }
    else
    {
        Node* insert = new Node(data);
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = insert;
        insert->prev = temp;
    }
    
}

void insertAtPos(Node* &head,int data,int pos)
{
    //insert at head
    if(pos==1)
    {
        insertionHead(head,data);
        return;
    }

    else{
        Node* insert = new Node(data);
        Node* temp = head;

        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
            i++;
        }
        insert->next = temp->next;
        temp->next = insert;
        insert->prev = temp;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    //Node* head = NULL;

    /*cout<<"\nAfter inserting a Data at Head : ";
    insertionHead(head,8);
    print(head);*/


    // cout<<"\nHere the LL traversal : \n";
    // print(head);

    
    cout<<"\nAfter inserting a Data at Head : ";
    insertionHead(head,8);
    print(head);

    cout<<"\nAfter inserting data at Last of the List : ";
    insertAtEnd(head,20);
    print(head);

    cout<<"\nAfter inserting data at any position of the List : ";
    insertAtPos(head,15,3);
    print(head);

    cout<<"\nHere the Length : ";
    cout<<getLength(head)<<endl;


    

    return 0;
}