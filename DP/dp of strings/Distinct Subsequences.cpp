class Solution {

private: 
    int f(int i, int j, string s, string t) {
        //base case
        if( j < 0 ) return 1; // we found the string
        if( i < 0 ) return 0; //string s exhausted
        //explore all ways
        if(s[i] == t[j]) {
            // there are 2 possibilities
            // 1 . pick it and i-1 , j-1
            // 2. dnt pick it look in i-1 strng
            return f(i-1,j-1,s,t) + f(i-1,j,s,t);
        }
        return f(i-1,j,s,t);
    }
public:
    int numDistinct(string s1, string s2) {
        int prime = 1e9+7;
        int n = s1.length();
        int m = s2.length();

        //recursion
        // return f(n-1,m-1,s,t);
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    } 
};