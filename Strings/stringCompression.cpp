#include <iostream>
#include <vector>
using namespace std;
void print(vector<char> & a){
    for(int i =0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
void compress(vector<char>& chars) {           
        int i=0;int n=chars.size();int ansIndex=0;         
        while(i<n){                                 
            int j=i+1;           
            while(j<n && chars[i]==chars[j]){          
                j++;                              
            }            
            chars[ansIndex++]=chars[i];           
            int cnt = j-i;                  
            if(cnt>1){           
            string count = to_string(cnt);          
            for(char ch:count){            
                chars[ansIndex++]=ch;      
            }                           
        }     
        i=j;   
        }      
}          
int main()
{
   vector<char> str ={'a','a','b','b','b','c','c'};
   compress(str);
   print(str);
   }