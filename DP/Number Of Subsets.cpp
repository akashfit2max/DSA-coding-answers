#include <bits/stdc++.h> 
int findWays(vector<int> &arr, int k)
{
    int n  = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    // return f(n-1,k,arr,dp);
    // tabulation
    //base case
    for(int i=0; i<n; i++) {
        dp[i][0] = 1;
    }
    if(arr[0] <= k ) dp[0][arr[0]] = 1;
    for(int ind=1; ind<n; ind++) {
        for(int target=0; target<=k; target++) {
            int not_take = dp[ind-1][target];
            int take = 0;
            if(arr[ind] <= target) {
                take = dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = (take + not_take);
        }
    }

    return dp[n-1][k];
}