#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //Destructor
    ~Node(){
        int value = this->data;
        if(this->next!=NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"\nMemory is free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &head,int element,int data)
{
    if(head==NULL)
    {
        Node* insert = new Node(data);
        head = insert;
        insert->next = insert;
    }
    else
    {
        Node* cur = head;
        while(cur->data != element){
            cur = cur->next;
        }
        Node* temp = new Node(data);
        temp->next = cur->next;
        cur->next = temp;
    }
}

void deleteNode(Node* &head,int value)
{
    // Empty List
    if(head == NULL)
    {
        cout<<"List is Empty..Please Check.."<<endl;
        return;
    }
    else{
        //Assuming value is present in the list
        Node* prev = head;
        Node* cur = prev->next;
        while(cur->data != value)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        // 1 Node list 
        if(cur==prev)
        {
            head=NULL;
        }
        // list >= 2 for that Case
        else if(head == cur)
        {
            head = prev;
        }
        cur->next = NULL;
        delete cur;
    }
}

void print(Node* head)
{
    Node* temp = head; 

    if(head==NULL)
    {   
        cout<<"Now the list is Empty..."<<endl;
    }

    do
    {
        cout<<head->data<<"\t";
        head = head->next;
    }while(head != temp);
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    cout<<"\nhead : ";
    insertNode(head,5,3);
    print(head);
/*
    cout<<"\nAfter inserting a value : ";
    insertNode(head,3,5);
    print(head);

    cout<<"\nAfter inserting a value : ";
    insertNode(head,5,7);
    print(head);

    cout<<"\nAfter inserting a value : ";
    insertNode(head,7,9);
    print(head);

    cout<<"\nAfter inserting a value : ";
    insertNode(head,5,10);
    print(head);

    cout<<"\nAfter inserting a value : ";
    insertNode(head,3,4);
    print(head);

    deleteNode(head,10);
    cout<<"\nAfter Deletion : "<<endl;
    print(head);
*/
    deleteNode(head,3);
    cout<<"\nAfter Deletion : "<<endl;
    print(head);

    return 0;
}