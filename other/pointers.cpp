#include <iostream>
#include <vector>
using namespace std;
void update(int *p){
    *p=*p+1;
    cout<<"inside "<<p<<endl;
}
void update(int **p){
    *p+=1;
    // cout<<"inside "<<p<<endl;
}
int main()
{
    // int i = 3;
    // int *p=&i;
    // cout<<p<<endl;
    // int *q=p;
    // p=p+3;
    // cout<<q<<endl;
    // cout<<p<<endl;
    // cout<<p-q<<endl;
// int temp[10]={8,9,1,7};
// int *p =&temp[0];
// cout<<sizeof(temp)<<endl;
// cout<<sizeof(p)<<endl;
//  cout<<*p<<endl;
//  p++;
// //  temp++;
//  cout<<*p<<endl;
// int num = 1;
// int *p = &num;
// cout<<"before "<<*p<<endl;
// update(p); 
// cout<<"update "<<*p<<endl; // p;
//-----------------------------------------------------

// int num = 1;
// int *p = &num;
// int **p2 = &p;
// int ***p3 = &p2;
// cout<<"1        "<<&num<<endl;
//  cout<<"P  =     "<<p<<endl;
//  cout<<"&p =     "<<&p<<endl;
//  cout<<"*p =     "<<*p<<endl;
//  cout<<"p2 =     "<<p2<<endl;
//  cout<<"&p2 =    "<<&p2<<endl;
//  cout<<"*p2 =    "<<*p2<<endl;
//  cout<<"p3 =     "<<p3<<endl;
//  cout<<"&p3 =    "<<&p3<<endl;
//  cout<<"*p3 =    "<<*p3<<endl;
//  cout<<"**p2 =   "<<**p2<<endl;
//  cout<<"**p3 =   "<<**p3<<endl;
//  cout<<"***p3 =  "<<***p3<<endl;

//-----------------------------------------------------

// cout<<"before "<<endl;
// cout<<num<<endl;
// cout<<*p<<endl;
// cout<<p<<endl;
// cout<<p2<<endl;
// update(p2);
// cout<<"after"<<endl;
// cout<<num<<endl;
// cout<<*p<<endl;
// cout<<p<<endl;
// cout<<p2<<endl;

//-------------------------------------------------------
// int first = 5;
// int *p = &first;
// int *q = p;
// (*q)++;
// (*p)++;
// cout<<first<<" "<<*p<<endl;
//---------------------------------------------------------
// int num = 0;
// int *p = 0 ;
// int first = 110;
// p = &first;
// cout<<*p<<endl;
//-------------------------------------------------------
// int first = 8;
// int second = 11;
// int *third = &second;
// first = *third;
// *third = *third+2;
// cout<<first<<" "<<second<<endl;
//---------------------------------------------------------
// int i =9;
// int *p = &i;
// p++;
// cout<<p<<" "<<*p;

// char ch[6]={'a','b','c','d','e'};
// char *p = &ch[1];
// cout<<p<<endl;
// char *ch = "hello";// bad code
// cout<<*(ch+1)<<endl;

// int i =9;
// int *p=0;
// *p = i;
// cout<<p<<endl;
// cout<<*p<<endl;
// cout<<i<<endl;
// cout<<&i<<endl;
// cout<<sizeof(i)<<endl;
// cout<<sizeof(p)<<endl;

}