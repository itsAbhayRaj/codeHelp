#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>> &arr){
    for(int i =0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void spiralPrint(vector<vector<int>> &arr){
int startingRow = 0;
int endingRow = arr.size()-1;
int startingCol = 0;
int endingCol =arr[0].size()-1;
int count = 0;int total  = arr.size() * arr[0].size();
while(count<total){
    for(int i =startingCol;i<=endingCol;i++){
        cout<<arr[startingRow][i]<<" ";count++;
    }
    startingRow++;
    for(int i = startingRow;i<=endingRow;i++){
        cout<<arr[i][endingCol]<<" "; count++;
    }
    endingCol--;
    for(int i =endingCol;i>=startingCol;i--){
        cout<<arr[endingRow][i]<<" ";count++;
    }
    endingRow--;
    for(int i = endingRow;i>=startingRow;i--){
        cout<<arr[i][startingCol]<<" "; count++;
    }
    startingCol++;
}
 }

int main()
{
    vector<vector<int>> arr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    print(arr);
    cout<<endl<<endl;
    spiralPrint(arr);
}