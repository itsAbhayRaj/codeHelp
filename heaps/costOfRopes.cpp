priority_queue<int,vector<int>,greater<int>>pq;
        if(arr.size()==1)return 0;
        for(int i:arr){
            pq.push(i);
        }
        int cost = 0;
        while(!pq.empty()){
            int r1 =pq.top();
            pq.pop();
            int r2 =pq.top();
            pq.pop();cost+=r1+r2;
            if(pq.empty())return cost;
            pq.push(r1+r2);
            
        }
        return cost;