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

Node* floydDetectLoop(Node* head)
{
    if(head==NULL)
    return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        
        slow = slow->next;

        if(slow==fast)
            return slow;
    }
    return NULL;
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
    return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow!=intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node* head)
{
    if(head==NULL)
    return ;
 
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next!=startOfLoop)
        temp = temp->next;

    temp->next = NULL;
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
    node6->next = node4;

    // cout<<"\nFull Linked list : \n";
    // print(head);

    if(floydDetectLoop(head)!=NULL)
    cout<<"Loop is present"<<endl;
    else
    cout<<"Loop is not present"<<endl;


    cout<<"Loop starting at : "<<getStartingNode(head)->data<<endl;

    removeLoop(head);
    print(head);

    

    return 0;
}