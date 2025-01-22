#include <iostream>
#include <vector>

using namespace std;
void print(int arr[],int n ){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int partition(int arr[],int s ,int e){
    int c=0;
    int pivot = arr[s];
    for(int i =s+1;i<=e;i++){
        if(pivot>=arr[i])
            c++;
    }
    int pivotIndex = s+c;
    swap(arr[s],arr[pivotIndex]);
    int i =s;int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
        return pivotIndex;
}

void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main()
{
   int  n = 8;
   int  arr[] = {6,6,-6,-2,-4,-6,2,-6};
   quickSort(arr,0,n-1);
   print(arr,n);
}
