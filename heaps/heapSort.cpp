#include<iostream>
using namespace std;
void heapify(int arr[],int n ,int i ){
    int largest = i;
    int left = 2*i;
    int right = 2*i +1;
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
int t = n;
while (t>1)
{
    swap(arr[1],arr[t]);
    t--;
    heapify(arr,t,1);

}

}

void print(int arr[],int size){
    for(int i=1;i<=size;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
int size = 5;
int arr[size+1] = {-1,70,60,55,45,50};
heapSort(arr,size);
print(arr,size);
}