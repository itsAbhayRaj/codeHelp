#include <iostream>
using namespace std;
string removeDuplicates(string s){
    
    int i =0;int n = s.size();
    for(int j=0;j<n;j++,i++ ){
        s[i]=s[j];
        if(i>0 && s[i-1]==s[i]){
            i-=2;
        }
    }
    return s.substr(0,i);
     
}

int main(){
    string s;string str;
    getline(cin,s);
    string result = removeDuplicates(s);
    cout<<result;
}