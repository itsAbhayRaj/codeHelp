#include<bits/stdc++.h>
using namespace std;
int F(int n,int dp[]){
        if(n==0 || n==1)
        return n;
        if(dp[n]!=-1){
                return dp[n];
        }
        dp[n] =  F(n-1,dp) + F(n-2,dp);
        return dp[n]; 
}
int main()
{
        int n;
        cin>>n;
        int dp[n+1];
        for(int i =0;i<=n;i++){
                dp[i] = -1;
        }
        cout<<F(n,dp);

}