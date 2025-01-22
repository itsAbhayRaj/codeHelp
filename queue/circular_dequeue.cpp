#include<iostream>
using namespace std;
// class queue{  //circular queue
//     int *arr;
//     int size;
//     int qfront;
//     int rear;
//     public:
//     queue(int s){
//         size = s;
//         qfront = rear = -1;
//         arr = new int[size];   
//     }
//     void push(int data){
//         if((rear==size-1 && qfront==0) || rear == qfront -1){
//             cout<<"Overflow"<<endl;
//             return ;
//         }
//         if(rear==-1){
//             qfront = rear =0;
//         }else if(rear==size-1){
//             rear = 0;
//         }else{
//             rear++;
//         }
//         arr[rear] = data;
//     }
//     void pop(){
//         if(rear==-1){
//             cout<<"Underflow"<<endl;
//             return;
//         }
//         int val = arr[qfront];
//         arr[qfront];
//         if(rear==qfront){
//             rear=qfront=-1;
//         }else if(qfront==size-1){
//             qfront = 0;
//         }else{
//             qfront++;
//         }
//     }
//     int front(){
//         if(this->isEmpty()){
//             return -1;
//         }
//         return arr[qfront];
//     }
//     bool isEmpty(){
//         return rear==-1;
//     }
// };
class Deque
{
public:
    int* arr;
    int front;
    int rear;
    int size;
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear=-1;
    }

    bool pushFront(int x)
    {
        if((rear==size-1 && front==0) || rear == front-1){
            return false;
        }
        if(front == -1){
            front = rear =0;
        }else if(front==0){
            front = size-1;
        }else{
            front--;
        }
        arr[front] = x;
         return true;
    }

    bool pushRear(int x)
    {
        if((rear==size-1 && front==0) || rear == front-1){
            return false;
        }
        if(front == -1){
            front = 0;rear=0;
        }else if(rear==size-1){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if(front == -1){
            return -1;
        }
        int val = arr[front];
        arr[front] = -1;
        if(front==rear){
            front = rear = -1;
        }else if(front==size-1){
            front  = 0;
        }else{
            front++;
        }
        return val;
    }

    int popRear()
    {
        if(front == -1){
            return -1;
        }
        int val = arr[rear];
        if(front==rear){
            front = rear = -1;
        }else if(rear==0){
            rear  = size-1;
        }else{
            rear--;
        }
        return val;
    }

    int getFront()
    {
        if(front==-1)return -1;
        return arr[front];
    }

    int getRear()
    {
        if(front==-1)return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
      return rear==-1;
    }

    bool isFull()
    {
        if((rear==size-1 && front==0) || rear == front-1){
            return true;
        }else{
            return false;
        }
    }
};
int main(){
    // queue q(4);
    Deque q(4);
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;

    q.pushFront(1);
    q.pushFront(2);
    q.pushFront(3);
    q.pushFront(4);
    q.pushFront(5);
    cout<<q.getFront()<<endl;
    q.popFront();
    cout<<q.getFront()<<endl;
    return 0;
}