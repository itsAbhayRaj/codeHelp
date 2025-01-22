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

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow;
}
Node *merge(Node *firstHalf, Node *secondHalf)
{
    if(firstHalf==NULL)return secondHalf;
    if(secondHalf==NULL)return firstHalf;
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(firstHalf!=NULL && secondHalf!=NULL){
        if(firstHalf->data < secondHalf->data){
            temp->next = firstHalf;
            firstHalf = firstHalf->next;
            temp= temp->next;
        }else{
            temp->next = secondHalf;
            secondHalf = secondHalf->next;
            temp = temp->next;
        }
    }
    while(firstHalf!=NULL){
temp->next = firstHalf;
            firstHalf = firstHalf->next;
            temp= temp->next;
    }

    while(secondHalf!=NULL){
temp->next = secondHalf;
            secondHalf = secondHalf->next;
            temp = temp->next;
    }
    return ans->next;
}
Node *mergeSort(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *middle = findMiddle(head);
    Node* secondHalf = middle->next;
    Node* firstHalf = head;
    middle->next = NULL;
    firstHalf = mergeSort(firstHalf);
    secondHalf = mergeSort(secondHalf);
    Node* result = merge(firstHalf, secondHalf);
    return result;
}

int main()
{
    Node *head = new Node(9);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertAtHead(head, 3);
    insertAtHead(head,3);
    print(head);
    Node* newHead = mergeSort(head);
    print(newHead);
}