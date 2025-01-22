#include <iostream>
#include <vector>

using namespace std;

class Node{
    
    public:

    int data;
    Node * next;
    Node * prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
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
        return l;
    }
    void insertAtHead(Node* &head,int d){
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
    void insertAtTail(Node* &tail,int d){
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
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
        toInsert->next->prev = toInsert;
        temp->next = toInsert;  
        toInsert->prev = temp;
    }
    void deleteNode(int pos,Node* &head){
        Node* temp = head;
        if(pos==1){
            temp->next->prev=NULL;
            head = temp->next;
            temp->next=NULL;
            delete temp;
            return;
        }
        for(int i =1;i<pos;i++){
            temp  = temp->next;
        }
        if(temp->next==NULL){
            temp->prev->next =NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev=temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    void reverse(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL){
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        head = prev->prev;
    }

    Node* reverse1(Node* head){
        if(head==NULL ||  head->next==NULL){
            
            return head;
        }

        Node* newHead=reverse1(head->next);
        Node * temp = head->prev;
        head->prev = head->next;
        head->next = temp;
        return newHead;
    }
int main(){
    Node * head = new Node(10);
    Node * tail = head;

    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);

    insertAtPosition(head,3,22);
    // print(head);
    // cout<<getLength(head)<<endl;

    // deleteNode(7,head);
    print(head);

    reverse(head);
    print(head);

    Node* newHead =reverse1(head);
    print(newHead);
}