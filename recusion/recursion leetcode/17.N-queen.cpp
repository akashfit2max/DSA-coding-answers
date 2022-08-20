class Solution {
public:
    void help(int col, vector<string>&board, vector<vector<string>>&ans, vector<int>&leftRow, vector<int>&leftDiagonal, vector<int>&rightDiagonal,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && leftDiagonal[row+col]==0 && rightDiagonal[n-1 + col-row]==0)
            {
                // no one to attack to we can keep the queen here
                board[row][col]='Q';
                // make the 3 direction as visited
                leftRow[row]=1;
                leftDiagonal[row+col]=1;
                rightDiagonal[n-1+col-row]=1;
                help(col+1,board,ans,leftRow,leftDiagonal,rightDiagonal,n);
                //back track
                board[row][col]='.';
                leftRow[row]=0;
                leftDiagonal[row+col]=0;
                rightDiagonal[n-1+col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        
        vector<int>leftRow(n,0), leftDiagonal(2*n-1,0), rightDiagonal(2*n-1,0);
        help(0,board,ans,leftRow,leftDiagonal,rightDiagonal,n);
        return ans;
    }
};