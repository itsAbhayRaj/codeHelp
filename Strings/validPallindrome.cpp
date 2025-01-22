#include <iostream>
#include <vector>
using namespace std;
bool isValid(char ch){
    if((ch <= 'z' && ch >='a')||(ch <= 'Z' && ch >='A')||(ch <= '9' && ch >='0')){
        return 1;
    }
        return 0;

}
char toLower(char ch){
    if(ch <= 'z' && ch >='a'){
        return ch;
    }else{
        return ch-'A'+ 'a';
    }
}
bool ifValidPallindrome(string s){
    string temp ="";
    for(int i =0;i<s.length();i++){
        if(isValid(s[i])){
            temp.push_back(s[i]);
        }
    }
    int st=0;int e=temp.length()-1;
    while(st<e){
        if(tolower(temp[st++])!=tolower(temp[e--]))
        return false;
    }
    return true;
}
int main(){
    string s;
    getline(cin,s);
    cout<<ifValidPallindrome(s);
}