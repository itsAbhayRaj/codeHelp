#include <iostream>
using namespace std;
int binarySearch(int arr[],int key,int s){
    int start = 0 ; int end = s-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}
int main()
{
  int even[] = {3,1};
  int odd[] = {3,4,5,8,9,10,11};
  cout<<binarySearch(even,3,2);
    cout<<"\n"<<binarySearch(odd,8,7);

}