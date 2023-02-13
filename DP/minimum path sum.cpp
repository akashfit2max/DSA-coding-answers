class Solution {
private:
    int helper(long long int i, long long int j, vector<vector<int>>& grid) {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 999;

        int up = grid[i][j] + helper(i-1,j,grid);
        int left = grid[i][j] + helper(i,j-1,grid);

        return min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return helper(m-1,n-1,grid);
        int dp[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) {
                    dp[i][j] = grid[0][0];
                }
                else {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};