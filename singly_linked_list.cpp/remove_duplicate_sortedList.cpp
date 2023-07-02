// Remove Duplicates from sorted List

#include<iostream>
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

void removeDuplicates(Node *head)
{
    if(head==NULL||head->next==NULL)
    return ;

    Node* cur=head;

    while(cur->next != NULL)
    {
        if(cur->data == cur->next->data)
        {
            Node* temp = cur->next->next;
            Node* deleteNode = cur->next;
            delete (deleteNode);
            cur->next = temp;
        }
        else
        {
            cur = cur->next;
        }
    }
    print (head);
}


/*void remove_Duplicates(Node* &head)
{
    Node* cur = head;
    Node* temp = head;
    Node* forward = cur->next;
    while(temp->next!= NULL){
        if(cur->data != forward->data&&forward!=NULL)
        {
            forward = forward->next;
            if(cur->data!=forward->data&&forward!=NULL)
                cur = cur->next;
            else
            {
                cur->next=cur->next->next;
                forward = forward->next;
            }
        }
        else{
            cur->next=cur->next->next;
            forward = forward->next;
        }
    temp = temp->next;
    }
    print(head);
}*/

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(2);
    Node* node4 = new Node(3);
    Node* node5 = new Node(3);
    Node* node6 = new Node(3);
    Node* node7 = new Node(4);

    Node* head = node1;
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    cout<<"After removing duplicates : ";
    removeDuplicates(head);

    return 0;
}