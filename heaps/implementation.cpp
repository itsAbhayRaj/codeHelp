#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    int arr[100];
    int size=0;
    
    void insert(int d){
        size++;
        int index = size;
        arr[size] = d;
        while(index/2 && arr[index/2] < d){
            swap(arr[index],arr[index/2]);
            index = index/2;
        }
    }
};
void print(MaxHeap heap){
    for(int i =1;i<=heap.size;i++){
        cout<<heap.arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    MaxHeap heap;
    heap.insert(50);
    heap.insert(55);
    heap.insert(53);
    heap.insert(52);
    heap.insert(54);
    // heap.insert(45);
    // heap.insert(78);
    // heap.insert(46);
   
    print(heap);
}