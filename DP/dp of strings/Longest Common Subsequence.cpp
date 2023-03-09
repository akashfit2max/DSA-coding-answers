class Solution {
private:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if(i==0 || j==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        // if the char matches
        //shifting og index
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
        }

        //else reduce alternate string and check if they match
        return dp[i][j] = max(f(i-1,j,s,t,dp) , f(i,j-1,s,t,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // return f(n,m,text1,text2,dp);

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                //base case
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                }
                // copy reccurence
                else if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};