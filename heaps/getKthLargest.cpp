#include <bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (pq.size() >= k)
            {
                if (pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
            else
            {
                pq.push(sum);
            }
        }
    }

    return pq.top();
}
// there is brute force for storing all subarrays