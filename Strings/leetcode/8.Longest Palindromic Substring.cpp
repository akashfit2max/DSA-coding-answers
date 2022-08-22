class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int maxlen=0;
        string ans="";
        // traverse diagonally
        for(int dif=0;dif<n;dif++)
        {
            for(int i=0,j=i+dif; j<n; i++,j++)
            {
                if(i==j)
                {
                    //length 1 always palindrome
                    dp[i][j]=1;
                }
                else if(dif==1)
                {
                    dp[i][j] = (s[i]==s[j]) ? 1 : 0;
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1])
                    {
                        dp[i][j]= 1;
                    }
                }
                
                if(dp[i][j])
                {
                    maxlen = max(maxlen,j-i+1);
                    ans = s.substr(i,maxlen);
                }
            }
        }
        return ans;
    }
};