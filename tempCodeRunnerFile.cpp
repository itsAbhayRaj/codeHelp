#include <iostream>
using namespace std;

int main(){
    char ch = '1';
    char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
    arr[8]  = (arr[1]-'0')+(arr[2]-'0')+'0';
    // arr[8] = num + '0';
    arr[1] = 0 + '0';
    cout<<arr[1]<<endl;
    // cout<<num;
    return 0;
}