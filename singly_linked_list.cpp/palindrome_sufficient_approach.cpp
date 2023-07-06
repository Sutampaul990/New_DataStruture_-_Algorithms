#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverse(Node *head)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (cur != NULL)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    // Your code here
    if (head->next == NULL)
        return true;

    // Finding the middle node of the List
    Node *middle = findMiddle(head);
    cout<<"Here the middle of the list : "<<middle->data<<endl;

    // reverse the rest part after middle
    Node *temp = middle->next;
    middle->next = reverse(temp);
    cout<<"After 1st reverse of the list : ";
    print(head);

    // comparing both part
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;

        head1 = head1->next;
        head2 = head2->next;
    }

    // Again reversing for getting the original list back
    temp = middle->next;
    middle->next = reverse(temp);
    cout<<"After 2nd reverse of the list : ";
    print(head);

    return true;
}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(3);
    Node* node5 = new Node(2);
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

    cout;
    if(isPalindrome(head))
    cout<<"Checking Palindrome or not : TRUE"<<endl;
    else
    cout<<"Checking Palindrome or not : FALSE"<<endl;

    return 0;
}