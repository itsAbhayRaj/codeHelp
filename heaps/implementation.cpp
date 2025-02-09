#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int size = 0;

    void insert(int d)
    {
        size++;
        int index = size;
        arr[size] = d;
        while (index / 2 && arr[index / 2] < d)
        {
            swap(arr[index], arr[index / 2]);
            index = index / 2;
        }
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "Empty Heap !!!";
            return;
        }
        int i = 1;
        arr[i] = arr[size];
        size --;

        while (1)
        {
            int parent = i;
            int child1 = i * 2;
            int child2 =(i * 2) + 1;
            if(child1<=size && arr[parent]<arr[child1] && arr[child2]<arr[child1]){
                swap(arr[i],arr[i * 2]);
                i = i*2;
            }else if(child2<=size && arr[parent]<arr[child2] && arr[child2]>arr[child1]){
                swap(arr[i],arr[(i * 2) + 1]);
                i = i*2 +1;
            }else {
break;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap heap;
    heap.insert(50);
    heap.insert(55);
    heap.insert(53);
    heap.insert(52);
    heap.insert(54);
    // heap.insert(45);
    // heap.insert(78);
    // heap.insert(46);
    heap.Delete();
    heap.Delete();
    heap.Delete();
    heap.Delete();
    heap.Delete();    heap.Delete();

    heap.print();
}