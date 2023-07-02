#include<bits/stdc++.h>

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

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head==NULL || head->next==NULL)
        return head;

    unordered_map<int,bool>visited;
    Node* cur = head;
    Node* prev= NULL;

    while(cur!=NULL)
    {
        if(visited[cur->data]==true)
        {
            Node* deleteNode = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete(deleteNode);
        } 
        else {
          visited[cur->data] = true;
          prev=cur;
          cur = cur->next;
        }
    }
    
    return head;
}

int main()
{
    Node* node1 = new Node(4);
    Node* node2 = new Node(2);
    Node* node3 = new Node(5);
    Node* node4 = new Node(4);
    Node* node5 = new Node(2);
    Node* node6 = new Node(2);

    Node* head = node1;
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    cout<<"After removing duplicates : ";
    head = removeDuplicates(head);
    print(head);

    return 0;
}