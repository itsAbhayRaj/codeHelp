#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void print(vector<char> & a){
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
    cout<<endl;
}
// void reverseWords(vector<char> &a){
//     vector<char> temp;
//     vector<vector<char>> result;
//     for(int i=0;i<=a.size();i++){
//         if(a[i]==' ' || i == a.size()){
//             reverse(temp.begin(),temp.end());
//             result.push_back(temp);
//             temp.clear();
//         }else{
//             temp.push_back(a[i]);
//         }
//     }
//     a.clear();
//     for(auto i:result){
//         for(auto j: i){
//             a.push_back(j);
//         }
//         a.push_back(' ');
//     }
// }

// void reverseWords(string &s){
//     int n=s.length();
//     string word="";
//     string result="";
//     for(int i=0;i<=n;i++){
//         if(s[i]==' ' || i==n){
//             reverse(word.begin(),word.end());
//             result+=word;
//             result+=" ";
//             word="";
//         }else{
//             word+=s[i];
//         }
//     }
//     s=result;
// }

// void reverseWords(string &s){
//     int n=s.length();
//     string word="";
//     string res="";
//     for(int i =n-1;i>=-1;i--){
//         if(s[i]==' ' || i==-1){
//             reverse(word.begin(),word.end());
//             res+=word;
//             res+=" ";
//             word="";
//         }else{
//             word+=s[i];
//         }
//     }
//     s = res;
    
// }

void reverseWords(vector<char> &a){
    reverse(a.begin(),a.end());
    int start=0;
    for(int i =0;i<=a.size();i++){
        if(i==a.size()|| a[i]==' '){
            reverse(a.begin()+start,a.begin()+i);
            start=i+1;
        }
    }
    
}
int main(){
    string s="the sky is blue";
    vector<char> v={'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    // cout<<"Enter string: ";
    // getline(cin,s);
    // for(int i=0;i<s.length();i++){
    //     v.push_back(s[i]);
    // }
    // cout<<s<<endl;
    // reverseWords(s);
    // cout<<s<<endl;
    print(v);
    reverseWords(v);
    
    print(v);
    return 0;
}