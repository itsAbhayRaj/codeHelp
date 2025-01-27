#include <bits/stdc++.h>
using namespace std;

// int largestRectangleArea(vector<int> &heights) // brute approach
// {
//     int area = 0;
//     for (int i = 0; i < heights.size(); i++)
//     {
//         int newArea = heights[i];
//         int moveLeft = i - 1;
//         int moveRight = i + 1;
//         while (moveLeft >= 0 && heights[moveLeft] >= heights[i])
//         {
//             newArea += heights[i];
//             moveLeft--;
//         }
//         while (moveRight < heights.size() && heights[moveRight] >= heights[i])
//         {
//             newArea += heights[i];
//             moveRight++;
//         }
//         if (newArea > area)
//         {
//             area = newArea;
//         }
//     }
//     return area;
// }
void print(vector<int> &arr);
vector<int> nextSmallerElement(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> result(n);
    st.push(-1);
    for(int i =n-1;i>=0;i--){
        int curr = arr[i];
        while(st.top()!=-1 && arr[st.top()] >= curr){
            st.pop();
        }
        result[i] = st.top();
        st.push(i);
    }
    return result;
}
vector<int> prevSmallerElement(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> result(n);
    st.push(-1);
    for(int i =0;i<n;i++){
        int curr = arr[i];
        while(st.top()!=-1 && arr[st.top()] >= curr){
            st.pop();
        }
        result[i] = st.top();
        st.push(i);
    }
    return result;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n);
    vector<int> prev(n);
    
    next = nextSmallerElement(heights);
    prev = prevSmallerElement(heights);
    print(next);
    print(prev);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(next[i]==-1){
            next[i] = n;
        }
        int width = next[i] - prev[i] - 1;
        int newArea = heights[i] * width;
        if (newArea > area)
        {
            area = newArea;
        }
    }
    return area;
}
void print(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> heights = { 0,1,1,0 };
    int area = largestRectangleArea(heights);
    cout << area << endl;
}