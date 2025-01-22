#include <bits/stdc++.h>
using namespace std;
// int celebrity(vector<vector<int>> m, int n)
// {
//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         bool isCelebrity = true;
//         int row = 0, col = 0;
//         while (col < n)
//         {
//             if (col!=i &&m[col][i] == 0)
//             {
//                 isCelebrity = false;
//                 cout<<col<<" "<<i<<endl;
//                 break;
//             }
//             col++;
//         }
//         if(!isCelebrity) continue;
//         while (row<n)
//         {
//             if (row!=i && m[i][row] == 1)
//             {
//                 isCelebrity = false;
//                 cout<<i<<" "<<row<<endl;
//                 break;
//             }
//             row++;
//         }
//         if (isCelebrity)
//         {
//             ans = i;
//         }
//     }
//     return ans;
// }

bool knows(int a, int b, vector<vector<int>> m){
    return m[a][b] == 1;
}
int celebrity(vector<vector<int>> m, int n){
    stack<int>s;
    for(int i =0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){
        int a = s.top();
        s.pop();    
        int b = s.top();
        s.pop();
        if(knows(a,b,m)){
            s.push(b);
        }else{
            s.push(a);
        }
    }
    for(int i =0;i<n;i++){
        if(s.top()!=i && knows(s.top(),i,m)){
            return -1;
        }
    }
    for(int i =0;i<n;i++){
        if(s.top()!=i && !knows(i,s.top(),m)){
            return -1;
        }
    }
    return s.top();
}

int main()
{
    vector<vector<int>> m = {
        {1, 0, 1},
        {1, 0, 1},
        {0, 0, 0}};
    int celeb = celebrity(m, 3);
    cout << celeb << endl
         << endl;
}