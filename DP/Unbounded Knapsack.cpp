#include <bits/stdc++.h>
int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    // base case
    if(ind == 0) {
        if(wt[0] <= W) {
            return W/wt[0] * val[0];
        }
        else {
            return 0;
        }
    }
    if(dp[ind][W] != -1) return dp[ind][W];

    // pick or not pick
    // not pick
    int not_pick = 0 + f(ind-1,W,val,wt,dp);
    int pick = INT_MIN;
    if(wt[ind] <= W) {
        pick = val[ind] + f(ind,W-wt[ind],val,wt,dp);
    }
    return dp[ind][W] = max(pick,not_pick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    // return f(n-1,w,profit,weight,dp);
    

    // tabulation
    for(int i=weight[0]; i<=w; i++) {
        dp[0][i] = i/weight[0] * profit[0];
    }

    for(int ind=1; ind<n; ind++) {
        for(int W=0; W<=w; W++) {
            int not_pick = 0 + dp[ind-1][W];
            int pick = INT_MIN;
            if(weight[ind] <= W) {
                pick = profit[ind] + dp[ind][W-weight[ind]];
            }
             dp[ind][W] = max(pick,not_pick);
        }
    }
    return dp[n-1][w];
}
