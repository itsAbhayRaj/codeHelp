#include <iostream>
#include <vector>

using namespace std;

class Node{
    
    public:

    int data;
    Node * next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            next = NULL;
            delete next;
        }
        cout<<"Memory free for Node with data "<<val<<endl;
    }

};

    void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next; 
        }
        cout<<endl;
    }
    int getLength(Node * head){
        Node * temp = head;
        int l =0;
        while(temp!=NULL){
            l++;
            temp = temp->next; 
        }
        cout<<endl;
        return l;
    }
    void insertAtHead(Node* &head,int d){
        Node* temp = new Node(d);
        temp -> next = head;
        head = temp;
    }
    void insertAtTail(Node* &tail,int d){
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
    void insertAtPosition(Node* &head ,int pos,int d){
        if(pos==1){
            insertAtHead(head,d);
            return;
        }
        Node* temp = head;
        for(int i =1 ;i<pos-1;i++){
            temp = temp->next;
        }
        if(temp->next == NULL){
            insertAtTail(temp,d);
            return;
        }
        Node* toInsert = new Node(d);
        toInsert->next = temp->next;
        temp->next = toInsert;
    }
    void deleteNode(int pos,Node* &head){
        Node* temp = head;
        if(pos==1){
            head = temp->next;
            temp->next=NULL;
            delete temp;
            return;
        }
        for(int i =1;i<pos;i++){
            temp  = temp->next;
        }
        if(temp->next==NULL){
            delete temp;
            return;
        }
        temp->next = NULL;
        delete temp;
    }
    Node* middle(Node* head){
        int len = getLength(head);
        int mid = len/2 +1;
        Node* temp = head;
        for(int i = 1;i<mid;i++){
            temp=  temp->next;
        }
        return temp;
    }
    Node* findMiddle(Node* head){ // optimised solution
        if(head->next==NULL)
        return head;
        Node* fast = head->next;
        Node* slow = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL)
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
int main(){
    Node * head = new Node(10);
    Node * tail = head;

    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    print(head);
    cout<<middle(head)->data<<endl;
    cout<<findMiddle(head)->data<<endl;
}