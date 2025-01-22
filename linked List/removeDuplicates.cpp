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
void removeDuplicates(Node* & head){
    Node* curr = head;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->next->data==curr->data){
            Node* toPoint = curr->next->next;
            delete(curr->next);
            curr->next = toPoint;
        }else{
            curr = curr->next;
        }
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
    Node *head = new Node(8);
    
    insertAtHead(head, 8);
    insertAtHead(head, 8);
    insertAtHead(head, 6);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    removeDuplicates(head);
    print(head);
}