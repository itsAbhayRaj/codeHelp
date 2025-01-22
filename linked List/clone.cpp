#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(Node *&head, int d)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(d);
    temp->next = newNode;
    newNode->next = NULL;
}

// Node * clone(Node* head){ // O(n) , O(n)
//     Node* cloneHead=new Node(head->data);
//     Node * temp=head;
//     while(temp!=NULL){
//         temp=temp->next;
//         if(temp!=NULL)
//         insert(cloneHead,temp->data);
//     }
//     unordered_map<Node*,Node*> oldToNew;
//     Node* oldtemp = head;
//     Node* newtemp = cloneHead;
//     while(oldtemp!=NULL){
//         oldToNew[oldtemp]=newtemp;
//         oldtemp=oldtemp->next;
//         newtemp=newtemp->next;
//     }
//     oldtemp=head;
//     newtemp=cloneHead;
//     while(oldtemp!=NULL){
//         newtemp->random=oldToNew[oldtemp->random];
//         oldtemp=oldtemp->next;
//         newtemp=newtemp->next;
//     }
//     return cloneHead;
// }

Node *clone(Node *head)
{
    Node *temp = head;
    Node *cloneHead = new Node(temp->data);
    while (temp != NULL)
    {
        temp = temp->next;
        if (temp != NULL)
            insert(cloneHead, temp->data);
    }
    Node *originalTemp = head;
    Node *cloneTemp = cloneHead;
    Node *next = originalTemp;
    while (originalTemp != NULL)
    {
        next = originalTemp->next;
        originalTemp->next = cloneTemp;
        originalTemp = next;
        next = cloneTemp->next;
        cloneTemp->next = originalTemp;
        cloneTemp = next;
    }

    originalTemp = head;
    cloneTemp = cloneHead;
    while (originalTemp != NULL)
    {
        if(originalTemp->random!=NULL)
        cloneTemp->random = originalTemp->random->next;
        originalTemp = cloneTemp->next;
        if (cloneTemp->next != NULL)
            cloneTemp = cloneTemp->next->next;
    }

    cloneTemp = cloneHead;
    originalTemp=head;
    while (cloneTemp != NULL)
    {
        originalTemp->next = cloneTemp->next;
        originalTemp = originalTemp->next;
        if (originalTemp != NULL)
            cloneTemp->next = originalTemp->next;
        cloneTemp = cloneTemp->next;
    }

    return cloneHead;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    // Node *node5 = new Node(5);
    Node *head = node1;
    // Node *tail = node5;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node4->next = node5;
    node1->random = node2;
    node2->random = node4;
    // node3->random = node5;
    // node4->random = node3;
    // node5->random = node2;

    print(head);
    Node *cloneHead = clone(head);
    Node *temp = cloneHead;
    while (temp != NULL)
    {
        if (temp->random != NULL)
            cout << temp->data << "->" << temp->random->data << endl;
        else
            cout << temp->data << "->" << "NULL" << endl;
        temp = temp->next;
    }
    cout << endl;
    print(cloneHead);
}