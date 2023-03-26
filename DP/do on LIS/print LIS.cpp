#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
   vector<int>dp(n,1);
   int maxi = INT_MIN;
   for(int ind=0; ind<n; ind++) {
       for(int prev_ind=0; prev_ind<=ind-1; prev_ind++) {
           if(arr[prev_ind] < arr[ind]) {
               dp[ind] = max(dp[ind] , 1 + dp[prev_ind]);
           }
       }
       maxi = max(maxi,dp[ind]);
   }
   return maxi;
    // Write Your Code here
}
