#include <iostream>
using namespace std;

string removeSpace(string str){
    for(int i=0;i<str.size();i++){
    if(str[i]==' ')
    str.replace(i,1,"@40");
    }
    return str;
}
int main(){
    string str;
    getline(cin,str);
    cout<<removeSpace(str);
}