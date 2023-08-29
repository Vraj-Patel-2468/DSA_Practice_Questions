class Solution {
private:
    void dfs(vector<vector<bool>> &flip_NP, vector<vector<char>> &board, int i, int j, int m ,int n) {
        flip_NP[i][j]=true;
        if(i-1>=0 && !flip_NP[i-1][j] && board[i-1][j]=='O') 
            dfs(flip_NP, board, i-1, j, m, n);
        if(i+1<m && !flip_NP[i+1][j] && board[i+1][j]=='O') 
            dfs(flip_NP, board, i+1, j, m, n);
        if(j-1>=0 && !flip_NP[i][j-1] && board[i][j-1]=='O') 
            dfs(flip_NP, board, i, j-1, m, n);
        if(j+1<n && !flip_NP[i][j+1] && board[i][j+1]=='O') 
            dfs(flip_NP, board, i, j+1, m, n);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(); if(m==0) return;
        int n=board[0].size();
        //Deciding which char is possible to flip and which one is not.
        vector<vector<bool>> flip_NP(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            if(board[i][0]=='O' && !flip_NP[i][0]) {
                flip_NP[i][0]=true;
                dfs(flip_NP, board, i, 0, m ,n);
            }
            if(board[i][n-1]=='O' && !flip_NP[i][n-1]) {
                flip_NP[i][n-1]=true;
                dfs(flip_NP, board, i, n-1, m ,n);
            }
        }
        for(int i=0; i<n; i++) {
            if(board[0][i]=='O' && !flip_NP[0][i]) {
                flip_NP[0][i]=true;
                dfs(flip_NP, board, 0, i, m ,n);
            }
            if(board[m-1][i]=='O' && !flip_NP[m-1][i]) {
                flip_NP[m-1][i]=true;
                dfs(flip_NP, board, m-1, i, m ,n);
            }
        }
        //Implementing the flips
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                if(!flip_NP[i][j] && board[i][j]=='O')
                    board[i][j]='X';
    }
};