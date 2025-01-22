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

    void print(Node* tail){
        Node* temp = tail;
        if(tail==NULL){
        cout<<"LIst is empty";
        return;
        }
        cout<<tail->data<<" ";
        while(tail->next!=temp){
            tail = tail->next; 
            cout<<tail->data<<" ";
        }
        cout<<endl;
    }
    void insertNode(Node* &tail,int element,int d){
        if(tail==NULL){
            Node* temp = new Node(d);
            tail = temp;
            temp->next = temp;
            return;
        }
        Node* curr = tail;
        while(curr->data!=element){
            curr=curr->next;
        } 
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
void deleteNode(int element,Node* &tail){

    Node* prev = tail;
    Node* curr = tail->next;
    if(curr==prev){
        tail=NULL;
        return;
    }

   while(curr->data!=element){
        prev = curr;
        curr = curr->next;
    } 

    if(curr==tail)
    tail = curr->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;    
   }

int main()
{
  Node* tail = NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    insertNode(tail,5,6);
    insertNode(tail,3,11);
    insertNode(tail,5,22);
    print(tail);
    // deleteNode(99,tail);
    deleteNode(22,tail);
    deleteNode(3,tail);
    insertNode(tail,4,99);

     print(tail);

}