#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node *reverse(Node *&head)
{

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
Node *solve(Node *first, Node *second)
{
    int carry = 0;
    Node *result = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;
        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int digit = (val1 + val2 + carry);
        carry = digit/10;
        insertAtHead(result, digit%10);
        if(first!=NULL)first=first->next;
        if(second!=NULL)second= second->next;
    }
    return result;
}
Node *add(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);
    Node *result = solve(first, second);
    // result = reverse(result);
    return result;
}

int main()
{
    Node *first = new Node(5);
    Node *second = new Node(5);
    insertAtHead(first, 4);
    // insertAtHead(first, 1);
    insertAtHead(second, 4);
    insertAtHead(second, 3);
    insertAtHead(second,9);
    print(first);
    print(second);

    Node *result = add(first, second);
    print(result);
}