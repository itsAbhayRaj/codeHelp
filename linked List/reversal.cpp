#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;  
        }
        cout<<"Memory freed "<<this->data<<endl;
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
void insert(Node* & head,int d){
    Node* curr = head;
    while (curr->next!=nullptr)
    {
        curr = curr->next;
    }
    Node * temp = new Node(d);
    curr ->next  = temp;
}

void reverse(Node* &head){
    if(head==NULL||head->next==NULL)
    return;
    Node* prev = NULL;
    Node* curr = head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// Node* reverse1(Node* head){
   

// }
void  reverse2(Node* &head,Node* curr,Node* prev){ //recursive function
   if(head==NULL || head->next==NULL){
    return ;
   }
   curr->next = prev;
    reverse2(head->next,head->next,curr);
    head = curr;
}

int main()
{
    
    Node* head = new Node(10);
    insert(head,11);
    insert(head,12);
    insert(head,13);
    insert(head,14);
    insert(head,15);
    print(head);
    reverse(head);
    print(head);
    reverse2(head,head,NULL);
    print(head);
    // Node* newHead = reverse1(head);
    // print(newHead);
}