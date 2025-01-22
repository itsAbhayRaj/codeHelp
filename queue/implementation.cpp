#include <iostream>
using namespace std;
struct queue
{
    int f;
    int r;
    int size;
    int *arr;
    queue(int s)
    {
        size = s+1;
        arr = new int[size];
        f = 0;
        r = 0;
    }

    void enque(int d)
    {
        if (r == size - 1 && f!=r)
        {
            cout << "Overflow"<<endl;
            return;
        }
        if(f==r && f!=0){
            f=0;
            r=0;
        }
        arr[r++] = d;
    }

    void dequeue(){
        if(f==r ){cout<<"empty"<<endl;return ;}
        arr[f++]=-1;
    }
    int front(){
        if(f==r ){cout<<"empty";return -1;}
        return arr[f];
    }
    int empty(){
        return f==r;
    }
};

int main(){
    queue q(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    // cout<<q.front()<<endl;
    // // q.dequeue();
    // cout<<q.front()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }
    q.dequeue();
    q.enque(88);
    cout<<q.front()<<endl;
    return 0;
}