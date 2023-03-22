class Solution {
private:
    bool f(int i, int j, string s, string p, vector<vector<int>>&dp) {
        //base case
        // both the string are over
        if(i==0 && j==0) return true;
        //if s is over but there is still some char in p
        if(i==0 && j>0) return false;
        //if j is over and there are still some char in j
        // s can only contain '*' as it represent blank
        if(j==0 && i>0) {
            for(int ii=1; ii<=i; ii++) {
                if(p[ii-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //if char match or '?' we redice the string
        if(p[i-1] == s[j-1] || p[i-1] == '?') {
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        }
        // if there is a '*'
        if(p[i-1] == '*') {
            // either you conside it as nothing or you reduce one char
            return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp); 
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n,m,s,p,dp);
        // tabulation
        dp[0][0] = true;
        for(int j=1; j<=m; j++) {
            dp[0][j] = false;
        }
        for(int i=1; i<=n; i++) {
            int f1 = true;
            for(int ii=1; ii<=i; ii++) {
                if(p[ii-1] != '*') {
                    f1 = false;
                    break;
                }
            }
            dp[i][0] = f1;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};