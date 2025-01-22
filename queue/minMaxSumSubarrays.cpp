#include <bits/stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[], int N, int k)
{
    deque<int> G; // decreasing order
    deque<int> S; // increasing order
    int i = 0;
    for (; i < k; i++)
    {
        while (!G.empty() && arr[G.back()] < arr[i])
        {
            G.pop_back();
        }
        while (!S.empty() && arr[S.back()] > arr[i])
        {
            S.pop_back();
        }
        G.push_back(i);
        S.push_back(i);
    }
    int sum = 0;
    for (; i < N; i++)
    {

        sum += arr[G.front()] + arr[S.front()];

        if (!S.empty() && S.front() == i - k)
        {
            S.pop_front();
        }
        if (!G.empty() && G.front() == i - k)
        {
            G.pop_front();
        }
        while (!G.empty() && arr[G.back()] < arr[i])
        {
            G.pop_back();
        }
        while (!S.empty() && arr[S.back()] > arr[i])
        {
            S.pop_back();
        }

        G.push_back(i);
        S.push_back(i);
    }
    sum+=arr[G.front()]+arr[S.front()];
    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, N, k);
    return 0;
}