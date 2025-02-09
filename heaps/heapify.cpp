#include<iostream>
using namespace std;
void print(int arr[],int size){
    for(int i=1;i<=size;i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapify(int arr[],int size,int i ){
    int smallest = i;
    int left = i*2 ;
    int right = i*2+1;
    if(left<=size && arr[smallest]>arr[left]){
        smallest = left;
    } if(right<=size && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,size,smallest);
    }
}
int main(){
    int size =5;
    int arr[size+1] = {-1,54,53,55,52,50};
    for(int i =size/2;i>0;i--){
        heapify(arr,size,i);
    }
    print(arr,size); 
}