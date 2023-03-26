class Solution {
private:
    int f(vector<int>& arr,int n, int ind, int prev, vector<vector<int>>& dp) {
        if(ind == n)
        return 0;
        
    if(dp[ind][prev+1] != -1)
        return dp[ind][prev+1];
    
    int notTake = 0 + f(arr,n,ind+1,prev,dp);
    
    int take = 0;
    
    if(prev == -1 || arr[ind] > arr[prev]){
        take = 1 + f(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev+1] = max(notTake,take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return f(nums,n,0,-1,dp);
        for(int ind=n-1; ind>=0; ind--) {
            for(int prev=ind-1; prev>=-1; prev--) {
                int not_take = dp[ind+1][prev+1];
                int take = INT_MIN;
                if(prev==-1 || nums[ind] > nums[prev]) {
                    take = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(take,not_take);
            }
        }
        return dp[0][0];
    }
};