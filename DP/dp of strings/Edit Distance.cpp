class Solution {
private:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        //base case
        // "" "hor"  - j+1
        if(i==0) return j;
        // "ho" ""
        if(j==0) return i;
        //if they match we reduce the string
        //hors ros - s and s match no operations are required
        if(s[i-1] == t[j-1]) {
            return dp[i][j] = f(i-1,j-1,s,t,dp);
        }

        if(dp[i][j] != -1) return dp[i][j];
        // if they dnt match we have 3 options insert,delete and replace
        int insert = 1 + f(i,j-1,s,t,dp);
        int del = 1 + f(i-1,j,s,t,dp);
        int replace = 1 + f(i-1,j-1,s,t,dp);

        // we need min
        return dp[i][j] = min(insert , min(del,replace));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n,m,word1,word2,dp);
        // tabulation
        for(int j=0; j<=m; j++) {
            dp[0][j] = j;
        }
        for(int i=0; i<=n; i++) {
            dp[i][0] = i;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j] , dp[i-1][j-1]));
                }
            }
        }

        return dp[n][m];


    }
};