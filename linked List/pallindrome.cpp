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

bool isPallindrome(Node* head){
    if(head==NULL || head->next==NULL)return true;
    Node * temp = head;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int s=0;int e = arr.size()-1;
    while(s<=e){
        if(arr[s++]!=arr[e--]){
            return false;
        }
    }
    return true;
}
Node * reverse(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
bool checkPallindrome(Node* head){
    if(head==NULL || head->next==NULL) return true;
    // for two elemets
    if(head->next->next==NULL){
        if(head->data!=head->next->data)return false;
        else return true;
    }
    Node * slow = head;
    Node * fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    //slow at middle 
    // reverse this half

    slow->next = reverse(slow->next);
    fast = slow->next;slow = head;
    while(fast!=NULL){
        if(slow->data!=fast->data)return false;
        slow=slow->next;fast=fast->next;
    }
    
    return true;
}

int main()
{
    
    Node* head = new Node(1);
    insert(head,1);
    insert(head,2);
    insert(head,2);
    insert(head,1);
    insert(head,1);
    print(head);
    
    // string result = isPallindrome(head) ? "pallindrome" : "Not pallallindrome";
    string result = checkPallindrome(head) ? "pallindrome" : "Not pallallindrome";
    cout<<result<<endl;
    print(head);
}