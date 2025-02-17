class Solution {
    bool canBePlaced(int r,int col ,vector<string>board ,int n){
        int x = r;
        int y = col;
        // row
        while(y>=0){
            if(board[x][y]=='Q')
            return false;
            y--;
        }
        y = col;
        // upper diagonal
        while(x>=0 && y>=0){
            if(board[x][y]=='Q')
            return false;
            x--;
            y--;
        }
        x = r;y= col;
        // lower diagonal
        while(x<n && y>=0){
            if(board[x][y]=='Q')
            return false;
            x++;y--;
        }
        return true;
    }
    void solve(int col,vector<string>config,vector<vector<string>> &res,int n){
        if(col==n){
            res.push_back(config);
            return;
        }
        for(int r =0;r<n;r++){
            if(canBePlaced(r,col,config,n)){
                config[r][col] = 'Q'; 
                solve(col+1,config,res,n);
                config[r][col] = '.'; 
            }
            
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> config(n,string(n,'.'));
solve(0,config,res,n);
        return res;
    }
};



class Solution {

    void solve(int col, vector<string> &config, vector<vector<string>>& res,
               int n,map<int, bool> &row,
        map<int, bool> &uDiagonal,
        map<int, bool>& lDiagonal) {
        if (col == n) {
            res.push_back(config);
            return;
        }
        for (int r = 0; r < n; r++) {
            if (!row[r] && !uDiagonal[col-r] && !lDiagonal[col+r]) {
                config[r][col] = 'Q';
                row[r] = true;
                uDiagonal[col-r] = true;
                lDiagonal[col+r] = true;
                solve(col + 1, config, res, n,row ,uDiagonal, lDiagonal);
                config[r][col] = '.';
                row[r] = false;
                uDiagonal[col-r] = false;
                lDiagonal[col+r] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        map<int, bool> row;
        map<int, bool> uDiagonal;
        map<int, bool> lDiagonal;
        vector<string> config(n, string(n, '.'));
        solve(0, config, res, n,row ,uDiagonal, lDiagonal);
        return res;
    }
};