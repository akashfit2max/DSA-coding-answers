class Solution {
private:
    int f(int ind, int T, vector<int>& coins, vector<vector<int>>& dp) {
        if(ind == 0) {
            // if the coins at 0th ind is divisible by current target we can return the t/arr[0];
            if(T%coins[0] == 0) return T/coins[0];
            // else we return a huge num
            return 1e9;
        }

        if(dp[ind][T] != -1 ) return dp[ind][T];

        // we dont pick it
         int not_take =  0 + f(ind-1,T,coins,dp);
        // if we take it
        int take = INT_MAX;
        if(coins[ind] <= T) {
            take = 1 + f(ind,T-coins[ind],coins,dp);
        }

        return  dp[ind][T] = min(take , not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans = f(n-1,amount,coins,dp);

        // if(ans >= 1e9) {
        //     return -1;
        // }
        // return ans;

        // tabulation

        for(int T=0; T<=amount; T++) {
            if(T % coins[0] == 0) {
                dp[0][T] = T/coins[0];
            }
            else {
                dp[0][T] = 1e9;
            }
        }

        for(int ind = 1; ind < n; ind++) {
            for(int T=0; T <= amount; T++) {
                 // we dont pick it
                int not_take =  0 + dp[ind-1][T];
                // if we take it
                int take = INT_MAX;
                if(coins[ind] <= T) {
                    take = 1 + dp[ind][T-coins[ind]];
                }
                dp[ind][T] = min(take , not_take);
            }
        }
        
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};