#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory freed for value "<<value<<endl;
    }
};

void insertAtHead(Node *&head, int data)
{

    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&tail, int data)
{

    Node *newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}

void insertAt(Node *&tail, Node *&head, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
    }
    else
    {
        Node *node = new Node(data);
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            insertAtTail(tail, data);
        }
        else
        {
            node->next = temp->next;
            temp->next = node;
        }
    }
}

void deleteNode(Node* &tail,Node *&head, int data)
{
    Node *temp = head;
    Node* slow = temp;
    int cnt = 0;
    while (temp->data != data)
    {
        slow = temp;
        temp = temp->next;
        cnt++;
    }
    if (cnt == 0)
    {
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
    else if (temp->next == nullptr)
    {
        slow->next = nullptr;
        tail = slow;
        temp->next = nullptr;
        delete temp;
    }
    else
    {
        slow->next  = temp->next;
        temp->next = nullptr;
        delete temp;
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
    cout<<endl;
}
int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    // Node *node2= new Node(2);head->next=node2;
    // Node *node3= new Node(3);node2->next = node3;
    // Node *node4= new Node(4);node3->next = node4;
    // Node *node5= new Node(5);node4->next=node5;
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    // insertAtTail(tail, 2);
    // insertAtTail(tail, 3);
    // insertAtTail(tail, 4);
    // insertAtTail(tail, 5);
    // insertAtTail(tail, 6);
    // insertAtTail(tail, 7);
    // insertAt(tail, head, 2, 10);
    cout << head->data << endl;
    cout << tail->data << endl;
    print(head);

    deleteNode(tail,head, 6);
    deleteNode(tail,head, 7);
    deleteNode(tail,head, 5);
    deleteNode(tail,head, 1);

    cout << head->data << endl;
    cout << tail->data << endl;
    print(head);
}