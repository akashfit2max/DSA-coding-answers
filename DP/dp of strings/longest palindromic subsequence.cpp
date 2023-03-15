class Solution {
private:
    int LCS(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) {
            for(int j=0; j<=m; j++) {
                if(i==0 || j==0) continue;
                else if(s[i-1] == t[j-1]) {
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
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        cout<<s<<"  "<<t;
        // for find the LPS we can call LCS for s and t
        return LCS(s,t);
    }
};