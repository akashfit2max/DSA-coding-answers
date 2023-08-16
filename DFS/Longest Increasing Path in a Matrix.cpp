class Solution {
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
private:
    int dfs(int r, int c, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int mx = 0;
        if(dp[r][c] != -1) return dp[r][c];
        for(int i=0; i<4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr < n && nr >= 0 && nc < m && nc >=0 && matrix[nr][nc] > matrix[r][c]) {
                mx = max(mx , dfs(nr,nc,n,m,matrix,dp));
            }
        }
        return dp[r][c] =1+ mx;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int longest = 0 , n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                longest = max(longest , dfs(i,j,n,m,matrix,dp));
            }
        }
        return longest;
    }
};