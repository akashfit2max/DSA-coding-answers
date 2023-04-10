class Solution {
private:
    int f(int ind, int n, vector<int>& arr, int k, vector<int>& dp) {
        // if ind exceeds the size
        if(ind == n) return 0;
        if(dp[ind] != -1) return dp[ind];
        // loop upto k and find the max element in each subarray and mul it with the len 
        int len = 0, max_ele = INT_MIN , ans = INT_MIN;
        for(int i = ind; i < min(n , ind+k); i++) {
            len++;
            // (1,15,7) (9) (2,5,10)
            max_ele = max(max_ele , arr[i]); //15
            int sum = (len * max_ele) + f(i+1,n,arr,k,dp); // next part
            ans = max(ans,sum); 
        }
        return dp[ind] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int>dp(n,-1);
        // return f(0,n,arr,k,dp);
        vector<int>dp(n+1,0);
        dp[n] = 0;
        for(int ind=n-1; ind >= 0; ind--) {
            int len = 0, max_ele = INT_MIN , ans = INT_MIN;
            for(int i = ind; i < min(n , ind+k); i++) {
                len++;
                // (1,15,7) (9) (2,5,10)
                max_ele = max(max_ele , arr[i]); //15
                int sum = (len * max_ele) + f(i+1,n,arr,k,dp); // next part
                ans = max(ans,sum); 
            }
            dp[ind] = ans;
        }
        return dp[0];
    }
};