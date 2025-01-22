#include <iostream>
#include <vector>
using namespace std;

string reverse(string str,int s,int e){
    if(s>e){
       return str;
    }
   //  swap(str[s],str[e]);
    return reverse(str,++s,--e);
    
    swap(str[s],str[e]);

}

int main()
{
   string str = "abcde";
//    string *s = &str;
   string s=reverse(str,0,str.length()-1);
   cout<<s<<endl;
}