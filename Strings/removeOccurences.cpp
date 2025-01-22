#include <iostream>
using namespace std;

string removeOccurrence(string str,string part){
    while(str.find(part)<str.size()){
    str.erase(str.find(part),part.size());
    }
    return str;
}
int main(){
    string str;string part;
    getline(cin,str);
    cin>>part;
    cout<<removeOccurrence(str,part);
}