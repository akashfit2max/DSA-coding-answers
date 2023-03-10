class Solution {
public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>>&dp) {
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        if(dp[ind][target] != -1) return dp[ind][target];

        // explore all paths
        bool not_take = f(ind-1,target,arr,dp);
        bool take = false;
        if(arr[ind] <= target) {
            take = f(ind-1,target-arr[ind],arr,dp);
        }

        return dp[ind][target] = take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) {
            sum += it;
        }
        if(sum%2 != 0) return false;
        int k = sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);
    }
};