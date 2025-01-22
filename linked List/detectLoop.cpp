#include <iostream>
#include <vector>
#include <map>
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

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
        return;
    }
    Node *curr = tail;
    while (curr->data != element)
    {
        curr = curr->next;
    }
    Node *temp = new Node(d);
    temp->next = curr->next;
    curr->next = temp;
}

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

bool detect(Node *head)
{
    if (head == NULL)
        return false;
    Node *temp = head;
    map<Node *, bool> visited;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout << "at node " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
Node* floydDetect(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) // can be in loop will not getting starting node of loop
        {
            return slow;
        }    
        
    }

    return NULL;
}
Node * startingNode(Node* head){
    Node* intersectionNode = floydDetect(head);
    Node* temp = head;
    while(temp!=intersectionNode){
        temp = temp->next;
        intersectionNode = intersectionNode->next;
    }
    return temp;
}

void  removeLoop(Node * &head){
    Node * start = startingNode(head);
    Node * temp = start->next;
    while(temp->next!=start){
        temp = temp->next;
    }
    temp->next = NULL;

}

int main()
{
    Node *head = NULL;

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 8);
    insertAtHead(head, 9);
    head->next->next->next->next->next->next = head->next;


    // print(head);
    // string result = detect(head) ? "loop" : "no loop";
    // cout << result << endl;
    string result2 = floydDetect(head) ? "loop" : "no loop";
    cout<<result2<<endl;
    cout<<"Starting Node at "<<startingNode(head)->data<<endl;
    removeLoop(head);
    result2 = floydDetect(head) ? "loop" : "no loop";
    cout<<result2<<endl;
    print(head);
}
