#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n=3;
    int m=5;
    //cin>>n;

    int** arr = new int*[n];
    for(int i =0;i<n;i++){
        arr[i] = new int[m];
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
      // cin>>arr[i][j];
      arr[i][j] = rand()%10;
    }
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<5;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    }
    delete []arr;
}