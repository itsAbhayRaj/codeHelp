#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i=0, j=0, first_row=0, first_column = 0;
    int last_row = rows - 1;
    int last_column = cols - 1;
    vector<int> result;
    while (first_row < rows && first_column < cols)
    {
        j = first_column;
        while (j <= last_column)
        {
            result.push_back(matrix[first_row][j++]);
        }
        first_row++;
        i = first_row;
        while (i <= last_row)
        {
            result.push_back(matrix[i++][last_column]);
        }
        last_column--;
        j = last_column;
        while (j >= 0)
        {
            result.push_back(matrix[last_row][j--]);
        }
        last_row--;
        i = last_row;
        while (i >= first_row)
        {
            result.push_back(matrix[i--][first_column]);
        }
        first_column++;
    }
    return result;
}
    void print(vector<int> arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<"nothing"<<endl;
    }
    int main()
    {
        vector<vector<int>> arr{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        vector<int> result = spiralOrder(arr);
        print(result);
    }