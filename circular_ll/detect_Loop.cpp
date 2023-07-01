#include<iostream>
#include<map>
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

// Detecting LOOP in LL
bool detectLoop(Node* head)
{
    if(head == NULL)
    return false;

    map<Node*,bool> visited;

    Node* temp = head;

    while(temp!=NULL)
    {
        // Cycle is Present
        if(visited[temp]==true)
        {
            cout<<"Present on element : "<<temp->data<<endl;
            return 1;
        }

        visited[temp] = true;

        temp = temp->next;
    }

    return 0;
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

    // cout<<"\nFull Linked list : \n";
    // print(head);

    // if(isCircular(head))
    // cout<<"It is circular in Nature"<<endl;
    // else
    // cout<<"It is singly linked list."<<endl;

    if(detectLoop(head))
    cout<<"Loop is present"<<endl;
    else
    cout<<"Loop is not present"<<endl;


    

    return 0;
}