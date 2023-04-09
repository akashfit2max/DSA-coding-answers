class Solution {
private:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, string & s, int n, vector<int>& dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = INT_MAX;
        string temp = "";
        for(int j=i; j<n; j++) {
            temp += s[j];
            if(isPalindrome(i,j,temp)) {
                int cost = 1 + f(j+1,s,n,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            //string[i...j]
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};