class Solution {
private:
    int f(int ind, int T, vector<int>& coins, vector<vector<int>>& dp) {
        if(ind == 0) {
            // if the coins at 0th ind is divisible by current target we can return the t/arr[0];
            if(T%coins[0] == 0) return 1;
            // else we return a huge num
            return 0;
        }

        if(dp[ind][T] != -1 ) return dp[ind][T];

        // we dont pick it
         int not_take =  f(ind-1,T,coins,dp);
        // if we take it
        int take = 0;
        if(coins[ind] <= T) {
            take = f(ind,T-coins[ind],coins,dp);
        }

        return  dp[ind][T] = take + not_take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // return f(n-1,amount,coins,dp);
        //tabulation
        for(int T=0; T<=amount; T++) {
           dp[0][T] = (T%coins[0] == 0); //it will either return 0 or 1
        }

        for(int ind=1; ind < n; ind++) {
            for(int T=0; T<=amount; T++) {
                int not_take =  dp[ind-1][T];
                // if we take it
                int take = 0;
                if(coins[ind] <= T) {
                    take = dp[ind][T-coins[ind]];
                }
                dp[ind][T] = take + not_take;
            }
        }
        return dp[n-1][amount];
    }
};