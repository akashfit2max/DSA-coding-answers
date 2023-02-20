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
int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(auto &it : arr) {
        totsum += it;
    }
    // 2 cond
    if(totsum-d < 0 || (totsum-d)%2) return false;
    vector<vector<int>>dp(n,vector<int>((totsum-d)/2 + 1,-1));
    return f(n-1,(totsum-d)/2 , arr,dp);
}


