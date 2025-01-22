#include <iostream>
using namespace std;

//  class Stack
// {
// private:
//     int *arr;

// public:
//     int size;
//     int top;
//     Stack(int size)
//     {
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }

//     void push(int number)
//     {
//         if (top == this->size - 1)
//         {
//             cout << "No space" << endl;
//             return;
//         }
//         top++;
//         arr[top] = number;
        
//     }
//     void pop()
//     {
//         if (top == -1)
//         {
//             cout << "No elements" << endl;
//             return;
//         }
//         arr[top] = -1;
//         top--;
//     }
//     int peek()
//     {
//         return arr[top];
//     }

//     bool isEmpty()
//     {
//         if (top == -1)
//             return true;
//         else
//             return false;
//     }
// };


struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class Stack{
    public:
    Node* head;
    Stack(){
        head = nullptr;
    }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void pop(){
        if(this->isEmpty()){
            cout<<"Stack Underflow!!!"<<endl;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }

    int peek(){
        if(isEmpty()){
            cout<<"Empty Stack"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
    bool isEmpty(){
        return head==nullptr;
    }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(8);
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
        s.push(8);

    s.pop();
    cout<<"\n"<<s.isEmpty()<<endl;
    cout<<s.peek();
}