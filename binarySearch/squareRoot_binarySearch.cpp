#include <iostream>
using namespace std;
int sqrtRoot(int n ){
   int s=0;int e=n;int ans;
   while(s<=e){
      int mid = s+(e-s)/2;
      int square = mid*mid;
      if(square == n){
         return mid;
      }else if(square<n){
         ans=mid;
         s= mid+1;
      }else{
         e=mid-1;
      }
   }
   return ans;
}
double morePrecision(int n ,int precision,int tempSol){
   double fact = 1;double ans = tempSol;
   for(int i =0;i<precision;i++){
      fact /= 10;
      for(double j = ans;j*j<n;j=j+fact){
         ans = j;
      }
   }
   return ans;
}
int main()
{
   int n;cout<<"Sqrt of number ";cin>>n;
   int tempSol  = sqrtRoot(n);
   cout<<tempSol<<endl;
   cout<<"More Precision "<<morePrecision(n,4,tempSol);
}