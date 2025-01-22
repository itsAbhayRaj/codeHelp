#include<iostream>
using namespace std;

void sayWords(int n){
    string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n==0) return;
    int digit = n%10;
    sayWords(n/10);

    cout<<words[digit]<<" ";
    
    
}
int main(){
    sayWords(430002234);
}