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

};

    void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next; 
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
   
    bool isCircular(Node* head){
        if(head==NULL){
            return true;
        }
        Node* temp = head->next;
        while(temp!=NULL && temp!= head){
            temp= temp->next;
        }
        if(temp==head)
        return true;
        return false;
    }
    bool isCircular1(Node* head){ // optimised solution
        if(head==NULL){
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }


int main(){
    Node * head =NULL;


    // insertAtHead(head,1);
    // insertAtHead(head,2);
    // insertAtHead(head,7);
    // insertAtHead(head,4);
    // insertAtHead(head,8);
    // insertAtHead(head,3);
    insertNode(head,1,1);
    insertNode(head,1,2);
    insertNode(head,2,5);
    insertNode(head,5,4);
    insertNode(head,4,3);
    insertNode(head,3,8);
    insertNode(head,8,14);


    string result = isCircular1(head) ? "circular" : "Not circular";
    cout<<result;

}
