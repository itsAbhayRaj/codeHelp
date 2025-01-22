#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
bool isPossible(vector<int> arr,int n,int m,int mid){
	int days = 1;
	int timeSum=0;
	for(int i =0;i<n;i++){
		if(timeSum+arr[i]<=mid){
			timeSum+=arr[i];
		}else{
			days++;
                        if (days > m || arr[i] > mid) {
                          return false;
                        }
                        timeSum= arr[i];
		}
	}
	return true;
}

long long solve(vector<int> time,int n,int m,int s,int e){
	if(s<=e){
		int mid = s+(e-s)/2;
		if(isPossible(time,time.size(),m,mid)){
			return solve(time,n,m,s,mid-1);
		}else{
			return solve(time,n,m,mid+1,e);
		}
	}else{
		return s;
	}
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	

	int sum=0;
	for(int i=0;i<n;i++){
		sum+=time[i];
	}
	int s=0;int e=sum;int ans = -1;
	return solve(time,n,m,s,e);

	// while(s<=e){
	// 	int mid = s+(e-s)/2;
	// 	if(isPossible(time,n,m,mid)){
	// 		ans = mid;
	// 		e=mid-1;
	// 	}else{
	// 		s=mid+1;
	// 	}
	// }
	// return ans;
}
int main()
{
        int n;
        cout<<"number of books ";
        cin>>n;
        cout<<"Pages in respective book "<<endl;
        vector<int> arr;
        for(int i =0;i<n;i++){
            cout<<i+1<<"th:- ";
            int d;
            cin>>d;
            arr.push_back(d);
        }
        cout<<"Students ? "<<endl;
        int m;
        cin>>m;
        cout<<ayushGivesNinjatest(n,m,arr);
}