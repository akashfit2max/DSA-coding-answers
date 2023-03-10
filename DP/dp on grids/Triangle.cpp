class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& triangle,int n) {
        // if it reacher the end return the current col val
        if(i==n-1) return triangle[n-1][j];
        //explore all paths
        int d = triangle[i][j] + helper(i+1,j,triangle,n);
        int dg = triangle[i][j] +  helper(i+1,j+1,triangle,n);

        return min(d,dg);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return helper(0,0,triangle,n);
        int dp[n][n];
        for(int j=0;j<n;j++) {
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};