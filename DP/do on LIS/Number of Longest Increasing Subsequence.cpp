class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
       int n = arr.size();
       if(n==1) return 1;
       // same as dp on LIS
       int maxi = INT_MIN;
       vector<int>dp(n,1),cut(n,1);
       for(int i=1; i<n; i++) {
           for(int p=0; p<i; p++) {
               if(arr[i] > arr[p] && 1 + dp[p] > dp[i]) {
                   dp[i] = 1 + dp[p];
                   cut[i] = cut[p];
               }
               else if (arr[i] > arr[p] && 1 + dp[p] == dp[i]) {
                   cut[i] += cut[p];
               }
           }
           maxi = max(maxi,dp[i]);
       }

       int ans = 0;
       for(int i=0; i<n; i++) {
           if(dp[i] == maxi) {
               ans += cut[i];
           }
       }
        return ans;
    }
};