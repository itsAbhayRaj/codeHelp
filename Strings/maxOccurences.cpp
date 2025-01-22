#include<iostream>
using namespace std;
char maxOccurence(string str){
    int occurences[26]={0};
    int number=0;
    for(int i =0;i<str.size();i++){
        if(str[i]<='z' && str[i]>='a'){
            number=str[i]-'a';
        }else{
            number=str[i]-'A';
        }
        occurences[number]++;
    }
    int max =-1;int ans=0;
    for(int i =0;i<26;i++){
        if(max<occurences[i]){
            max=occurences[i];
            ans=i;
        }
    }
    return 'a'+ans;
}
int main(){
    string str;
    cin>>str;
    cout<<maxOccurence(str);
}