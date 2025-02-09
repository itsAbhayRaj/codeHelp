//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    void heapify(vector<int> & arr,int size,int i ){
        int larger = i;
        int left = 2*i+1;
        int right = 2* i +2;
        if(left<size && arr[larger]<arr[left]){
            larger = left;
        }
        if(right<size && arr[larger]<arr[right]){
            larger = right;
        }
        if(larger!=i){
            swap(arr[larger],arr[i]);
            heapify(arr,size,larger);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> res (a.size()+b.size());
        copy(a.begin(),a.end(),res.begin());
        copy(b.begin(),b.end(),res.begin()+a.size());
        int size   = n+m;
        for(int i =size/2 - 1 ; i>=0;i--){
            heapify(res,size,i);
        }
        return res;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends