class Solution {
private:
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
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        int lcsLen = longestCommonSubsequence(s,t);
        return n-lcsLen;
    }
};