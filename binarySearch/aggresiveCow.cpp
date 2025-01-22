#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &stalls,int mid,int k){
        int cowCount=1;
        int adjacentCow=stalls[0];
        for(int i=0;i<stalls.size();i++){
                if(stalls[i]-adjacentCow >=mid){
                        cowCount++;
                        if(cowCount==k)
                                return true;
                    adjacentCow=stalls[i];
                }
        }
        return false;
}

int solve(vector<int> stalls,int k,int s,int e){
        if(s>e)return s-1;

        int mid = s+(e-s)/2;

        if(isPossible(stalls,mid,k)){
                return solve(stalls,k,mid+1,e);
        }else{
                return solve(stalls,k,s,mid-1);
        }
}
int maxMinimumDist(vector<int> &stalls, int k)
{
        int s=0;
        int maxi=-1;
        int ans=-1;
        sort(stalls.begin(),stalls.end());
        for(int i=0;i<stalls.size();i++){
                maxi = max(stalls[i],maxi);
        }
        int e = maxi;
        return solve(stalls,k,s,e);
        // while(s<=e){
        //         int mid = s+(e-s)/2;
        //         if(isPossible(stalls,mid,k)){
        //                 ans = mid;
        //                 s=mid+1;
        //         }else{
        //                 e=mid-1;
        //         }
        // }
        // return ans;
}
int main()
{
  int n;
        cout<<"number of Stalls ";
        cin>>n;
        cout<<"No of Cows ? ";
        int m;
        cin>>m;
        cout<<"Area of stalls "<<endl;
        vector<int> arr;
        int x;
        for(int i =0;i<n;i++){
            cin>>x;
            arr.push_back(x);
        }
        
        cout<<maxMinimumDist(arr,m);
}