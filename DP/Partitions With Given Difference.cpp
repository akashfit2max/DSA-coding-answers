#include <bits/stdc++.h> 
int mod = (int)(1e9+7);

int f(int ind, int sum, vector<int> &arr, vector<vector<int>>&dp)
{
    if(ind == 0) {
        if(arr[0]==0 && sum==0) return 2;
        if(sum == 0 || arr[0] == sum) return 1;
        else return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int not_take = f(ind-1,sum,arr,dp);
    int take = 0;
    if(arr[ind] <= sum) {
        take = f(ind-1,sum-arr[ind],arr,dp);
    }
    return dp[ind][sum] = (not_take + take)%mod;

}
int findWays(vector<int> &arr, int k)
{
    int n  = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    // if in the 0th ind is "0"
    if(arr[0] == 0) dp[0][0] = 2;
    // if it doesn't contain 0
    else dp[0][0] = 1;

    if(arr[0] != 0 &&  arr[0] <= k) dp[0][arr[0]] = 1;
    for(int ind=1; ind<n; ind++) {
        for(int target=0; target<=k; target++) {
            int not_take = dp[ind-1][target];
            int take = 0;
            if(arr[ind] <= target) {
                take = dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = (take + not_take)%mod;
        }
    }

    return dp[n-1][k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(auto &it : arr) {
        totsum += it;
    }
    // 2 cond
    if(totsum-d < 0 || (totsum-d)%2) return false;
    vector<vector<int>>dp(n,vector<int>((totsum-d)/2 + 1,-1));
    // return f(n-1,(totsum-d)/2 , arr,dp);
    return findWays(arr,(totsum-d)/2);
}


