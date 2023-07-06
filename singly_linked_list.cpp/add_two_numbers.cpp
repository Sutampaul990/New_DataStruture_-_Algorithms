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
void insertAtEnd(Node *&head, Node *&tail, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *listAdd(Node *first, Node *second)
{

    int carry = 0;
    Node* head = NULL;
    Node* tail = NULL;

    while(first!=NULL || second!=NULL || carry != 0)
    {
        int val1 = 0;
        if(first!=NULL)
            val1 = first->data;
        
        int val2 = 0;
        if(second!=NULL)
            val2 = second->data;
        
        int sum = carry+val1+val2;
        int digit = sum%10;

        insertAtEnd(head,tail,digit);

        carry = sum/10;

        if(first!=NULL)
            first = first->next;

        if(second!=NULL)
            second = second->next;
    }
    return head;
}

/*
Node *listAdd(Node *first, Node *second)
{
    int digit = 0;
    int sum = 0;
    int carry = 0;
    Node *head = NULL;
    Node *tail = NULL;

    while (first != NULL && second != NULL)
    {
        sum = carry + first->data + second->data;

        digit = sum % 10;

        // Creating and inserting in a list
        insertAtEnd(head, tail, digit);

        carry = sum / 10;

        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        sum = carry + first->data;

        digit = sum % 10;

        // Creating and inserting in a list
        insertAtEnd(head, tail, digit);

        carry = sum / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        sum = carry + second->data;

        digit = sum % 10;

        // Creating and inserting in a list
        insertAtEnd(head, tail, digit);

        carry = sum / 10;
        second = second->next;
    }
    while (carry != 0)
    {
        sum = carry;

        digit = sum % 10;

        // Creating and inserting in a list
        insertAtEnd(head, tail, digit);

        carry = sum / 10;
    }

    return head;
}
*/
// Function to add two numbers represented by linked list.
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // code here
    // Reversing both list
    first = reverse(first);
    second = reverse(second);

    // Adding
    Node *addition = listAdd(first, second);

    // Reversing the adding list
    return reverse(addition);
}
int main()
{
    Node *first = new Node(1);
    Node *node1 = new Node(3);
    Node *node2 = new Node(5);

    first->next = node1;
    node1->next = node2;
    node2->next = NULL;

    Node *second = new Node(2);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);

    second->next = node3;
    node3->next = node4;
    node4->next = NULL;

    cout << "First List : ";
    print(first);
    cout << "\nSecond List : ";
    print(second);

    cout<<"Addition : ";
    Node* head = addTwoLists(first,second);
    print(head);

    return 0;
}