#include <iostream>
#include <vector>
using namespace std;

bool check(string str,int s,int e){
    if(s>e){
       return true;
    }
    if(str[s]!=str[e])
        return false;
    else
        return check(str,++s,--e);
    

}

int main()
{
   string str = "abbfa";
//    string *s = &str;
   string s=check(str,0,str.length()-1)?"yes":"no";
   cout<< s;
} 