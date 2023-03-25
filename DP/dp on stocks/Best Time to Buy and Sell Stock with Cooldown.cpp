class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        // bottom up
        long profit;
        for(int ind=n-1; ind>=0; ind--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy==1) {
                    profit = max(-prices[ind]+dp[ind+1][0] , dp[ind+1][1]);
                }
                else {
                    profit = max(prices[ind] + dp[ind+2][1] , dp[ind+1][0]);
                }

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};