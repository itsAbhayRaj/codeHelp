class Solution {
    int ptr[3501];
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int miniE = -1;
    int miniInd = -1;
    int maxiE=  -1;
    int range = INT_MAX;
    for(int i =0;i<nums.size();i++){
        ptr[i] = 0;
    }
    while(1){
        miniInd = -1;
        mini= INT_MAX;
        maxi = INT_MIN;
        bool flag = 0;
        for(int i =0;i<nums.size();i++){
            if(ptr[i]==nums[i].size()){
                flag = true;break;
            }
            if(ptr[i]<nums[i].size() && nums[i][ptr[i]] < mini){
                miniInd = i;
                mini = nums[i][ptr[i]];
            }
            if(ptr[i]<nums[i].size() && nums[i][ptr[i]] > maxi){
                maxi = nums[i][ptr[i]];
            }
        }
        if(flag)break;
        ptr[miniInd]++;
        if ((maxi - mini) < range) {
            miniE = mini;
            maxiE = maxi;
            range = maxi - mini;
        }
    }
    return {miniE,maxiE};
    }
};











// optimal using heap
class Solution {
    struct node {
        int data;
        int row;
        int col;
        node(int d, int r, int c) {
            this->data = d;
            this->row = r;
            this->col = c;
        }
    };
    struct c {
        bool operator()(node* a, node* b) { return a->data > b->data; }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<node*, vector<node*>, c> pq;
        for (int i = 0; i < nums.size(); i++) {
            node* temp = new node(nums[i][0], i, 0);
            pq.push(temp);
            maxi = max(maxi, nums[i][0]);
        }
        int start = pq.top()->data;
        int end = maxi;
        while (!pq.empty()) {
            node* tmp = pq.top();
            pq.pop();
            mini = tmp->data;
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            if (tmp->col + 1 < nums[tmp->row].size()) {
                maxi = max(maxi, nums[tmp->row][tmp->col + 1]);
                node* next = new node(nums[tmp->row][tmp->col + 1], tmp->row,
                                      tmp->col + 1);
                pq.push(next);
            } else {
                break;
            }
            
        }
        return {start, end};
    }
};