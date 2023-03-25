class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // return f(0,1,2,prices,n,dp);
        // tabulation
        int profit;
        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy==1) {
                        profit = max(-prices[ind] + dp[ind+1][0][cap] , dp[ind+1][1][cap]);
                    }
                    else {
                        profit = max(prices[ind] + dp[ind+1][1][cap-1] , dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
        // we need to take the max of all trans
        // int ans = 0;
        // for(int cap=0; cap<=k; cap++) {
        //     ans = max(ans , dp[0][1][cap]);
        // }
        // return ans;
    }
};