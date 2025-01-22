#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //int m=n;
    //float nf = (float) n;
    bool flag = false;
    for(int i =1;i<=31;i++){
        int ans = pow(2,i);
        if(ans==n){
            flag = true;
            break;
        }
        }    
    // //while(m!=0){
    //   //  float qoutient = nf/2.0;
    //     // nf=nf/2.0;
    //    // if(qoutient==1.0){
    //         flag = true;
    //         break;
    //     }
    //     m/=2;
    // }
    cout<<flag;    
}