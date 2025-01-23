#include <iostream>
using namespace std;

int main(){
    int n=5;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
                if(i==0||i==n-1||j==0||j==i){
                    cout<<j+1<<"";}
                    else{
                        cout<<" tdf";
                    }
        }
        cout<<endl;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<(2*(n-i)-1);j++){
    //         if(j%2){
    //             cout<<"* ";
    //         }else{
    //             cout<<n-i<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
}