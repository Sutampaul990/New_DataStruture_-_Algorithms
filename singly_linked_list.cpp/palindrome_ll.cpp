#include<iostream>
#include<vector>
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


    bool checkPalindrome(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<=e)
        {
            if(arr[s]!=arr[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> arr;
        Node* temp = head;
        while(temp!=NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);
    }

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(1);
    Node* node3 = new Node(2);
    Node* node4 = new Node(2);
    Node* node5 = new Node(1);
    Node* node6 = new Node(1);

    Node* head = node1;
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    cout<<"\nFull Linked list : \n";
    print(head);

    cout<<"Checking Palindrome or not : ";
    if(isPalindrome(head))
    cout<<"TRUE"<<endl;
    else
    cout<<"FALSE"<<endl;

    return 0;
}