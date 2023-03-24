#include <bits/stdc++.h>
using namespace std;

long f(int ind, int buy, long *values, int n, vector<vector<long>>& dp) {
    if(ind == n) return 0;
    long profit = 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy) {
        profit = max(-values[ind] + f(ind+1,0,values,n,dp) , f(ind+1,1,values,n,dp));
    }
    else {
        profit = max((values[ind] + f(ind+1,1,values,n,dp)) , f(ind+1,0,values,n,dp));
    }
    return dp[ind][buy] = profit;
} 
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n+1,vector<long>(2,-1));
    // return f(0,1,values,n,dp);
    
    //base condition
    dp[n][0] = dp[n][1] = 0;
    
    long profit;
    
    for(int ind= n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -values[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], values[ind] + dp[ind+1][0]);
            }
            
            dp[ind][buy]  = profit;
        }
    }
    return dp[0][0];

}