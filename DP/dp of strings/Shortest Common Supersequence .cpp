class Solution {
private:
    string findLCS(string& s, string& t, int n, int m) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n ; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        int LCSlen =  dp[n][m];

        int SSlen = (n+m)-LCSlen;
        cout<<SSlen;
        string ans = "";

        int ind = SSlen-1 , i=n , j=m;

        while(i>0 && j>0) {
            if(s[i-1] == t[j-1]) {
                ans += s[i-1];
                ind--;
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                ans += s[i-1];
                i--;
            }
            else {
                ans += t[j-1];
                j--;
            }
        }

        while(i > 0) {
            ans += s[i-1];
            i--;
        }
        while(j > 0) {
            ans += t[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
public:
    string shortestCommonSupersequence(string s, string t) {
        // find lcs and get the len of the super seq = n+m-len(lcs);
        int n = s.length();
        int m = t.length();

        return findLCS(s,t,n,m);

        
    }
};