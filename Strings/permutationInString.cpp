#include <iostream>
using namespace std;
bool ifEquals(int arr1[],int arr2[]){
    for(int i =0;i<26;i++){
            if(arr1[i]!=arr2[i])
                return false;
    }
    return true;
}
bool search(string s1,string s2){
    int count1[26] = {0};
    for(int i =0;i<s2.length();i++){
        int index = s2[i]-'a';
        count1[index]++;
    }
    int i =0;int windowSize = s2.length();
    int count2[26]={0};
    while (i<windowSize&&i<s1.length())
    {
        int index = s1[i++]-'a';
        count2[index]++;
        }
    if(ifEquals(count1,count2)){
        return true;
    }
    while(i<s1.length()){
        int index = s1[i]-'a';
        count2[index]++;
         index = s1[i-windowSize]-'a';
        count2[index]--;
        i++;
        if(ifEquals(count1,count2)){
            return true;
        }
    }
    return false;
     
}

int main(){
    string s;string str;
    getline(cin,s);
    cin>>str;
    string result = (search(s,str)) ? "Present":"Not Present ";
    cout<<result;
}