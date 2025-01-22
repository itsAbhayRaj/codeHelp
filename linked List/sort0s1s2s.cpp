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
void sort1(Node *&head)
{
    int zeroes = 0, ones = 0, twos = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroes++;
        }
        else if (temp->data == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroes != 0)
        {
            temp->data = 0;
            zeroes--;
        }
        else if (ones != 0)
        {
            temp->data = 1;
            ones--;
        }
        else
        {
            temp->data = 2;
            twos--;
        }
        temp = temp->next;
    }
}
void insertAtTail(Node* &tail,Node * temp){
    tail->next = temp;
    tail = temp;
}
void sort2(Node * &head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
           insertAtTail(zeroTail,temp);
        }
        else if (temp->data == 1)
        {
            insertAtTail(oneTail,temp);
        }
        else
        {
            insertAtTail(twoTail,temp);
        }
        temp = temp->next;
    }

    head = zeroHead->next;
    if(oneHead!=oneTail){
    zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;

    twoTail->next = NULL;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

}

int main()
{
    Node *head = new Node(1);

    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    // sort1(head); // data replacement
    sort2(head); // merging three list
    print(head);
}