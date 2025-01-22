#include <iostream>
#include <vector>
using namespace std;
class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data;
        Node* child = temp->child ;
        while(child!=NULL){
            cout<<"->"<<child->data;
            child = child->child;
        }
        cout<<"||";
        temp = temp->next;
    }
}

  int main(){
    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(20);
    head->child = new Node(2);
    head->child->child = new Node(3);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);
    head->next->next->child = new Node(8);
    head->next->next->next->child = new Node(12);
    print(head);cout<<endl;
    // Node* newhead = flatten(head);
    // print(newhead);
  }