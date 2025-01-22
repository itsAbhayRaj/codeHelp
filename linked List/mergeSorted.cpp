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

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
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

Node *merge1(Node *&first, Node *&second)
{ // naive approach

    Node *head = new Node(-1);
    Node *curr = head;
    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            curr->next = first;
            curr = curr->next;
            first = first->next;
        }
        else
        {
            curr->next = second;
            curr = curr->next;
            second = second->next;
        }
    }
    while (first != NULL)
    {
        curr->next = first;
        curr = curr->next;
        first = first->next;
    }
    while (second != NULL)
    {
        curr->next = second;
        curr = curr->next;
        second = second->next;
    }
    return head->next;
}
Node* solve(Node* first,Node* second){
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    Node* next2 = second->next;
    while(next1!=NULL && curr2!=NULL){
        if(curr1->data <= curr2->data && curr2->data <= next1->data){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            
        }else{
            curr1 = next1;
            next1 = next1->next;
        }
    }
    return first;
}

Node *merge2(Node *first, Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;
    if (first->data < second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
int main()
{
    Node *first = new Node(5);
    Node *second = new Node(1);
    insertAtHead(first, 4);
    insertAtHead(first, 1);
    insertAtHead(second, 3);
    insertAtHead(second, 2);
    print(first);
    print(second);

    // Node* merged = merge1(first, second);
    // cout<<merged->data<<endl;
    Node *merged = merge2(first, second);
    print(merged);
}