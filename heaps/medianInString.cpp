#include<queue>
int signum(int a,int b){
	if(a==b) return 0;
	if(a>b) return 1;
	if(a<b) return -1;
}
void getMedian(int element  ,priority_queue<int ,
vector<int> ,greater<int>> &mini,priority_queue<int> &maxi ,
int &median){

	switch (signum(maxi.size(),mini.size())){

	case 0: 
			if(element > median){
				mini.push(element);
				median = mini.top();
			}else{
				maxi.push(element);
				median = maxi.top();
			}
			break;

	case 1:
			if(element > median){
				mini.push(element);
				median = (maxi.top()+mini.top())/2;
			}else{
				mini.push(maxi.top());maxi.pop();
				maxi.push(element);
				median = (maxi.top()+mini.top())/2;
			}
			break;

	case -1:	
			if(element > median){
				maxi.push(mini.top());mini.pop();
				mini.push(element);
				median = (maxi.top()+mini.top())/2;
			}else{
				maxi.push(element);
				median = (maxi.top()+mini.top())/2;
			}
			break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	int median =0;
	vector<int> res;
	priority_queue<int> maxi;
	priority_queue<int ,vector<int> ,greater<int>> mini;
	for(int i =0;i<n;i++){
		getMedian(arr[i],mini,maxi,median);
		res.push_back(median);
	}
	return res;
}
