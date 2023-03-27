#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
   vector<int>dp(n,1);
   int maxi = INT_MIN;
   vector<int>hash(n);
   int lastInd;
   for(int ind=0; ind<n; ind++) {
       hash[ind] = ind;
       for(int prev_ind=0; prev_ind<=ind-1; prev_ind++) {
           if(arr[prev_ind] < arr[ind] && 1+dp[prev_ind] > dp[ind]) {
               dp[ind] = 1 + dp[prev_ind];
               hash[ind] = prev_ind;
           }
       }
       if (dp[ind] > maxi) {
         maxi = dp[ind];
         // the index for the LIS
         lastInd = ind;
       }
   }

    vector<int>temp;
    temp.push_back(arr[lastInd]);
    while(hash[lastInd] != lastInd) {
        lastInd = hash[lastInd];
        temp.push_back(arr[lastInd]);
    }
    reverse(temp.begin(),temp.end());
    for(auto it : temp) cout<<it<<" ";
    cout<<endl;
    return maxi;
    // Write Your Code here
}
