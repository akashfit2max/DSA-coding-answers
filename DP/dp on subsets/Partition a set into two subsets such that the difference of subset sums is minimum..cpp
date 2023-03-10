#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum = 0;
	for(auto it : arr) {
		totalsum += it;
	}
	vector<vector<bool>>dp(n,vector<bool>(totalsum+1,0));
	for(int ind = 0; ind<n; ind++) {
		dp[ind][0] = true;
	}
	if(arr[0] <= totalsum )dp[0][arr[0]] = true;
	for(int ind=1; ind<n; ind++) {
        for(int target=1; target<=totalsum; target++) {
            bool not_take = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) {
                take = dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = take | not_take;
        }
    }

	int mini = 1e9;
	for(int s1=0; s1<=totalsum/2; s1++) {
		if(dp[n-1][s1]) {
			mini  = min(mini , abs(s1-(totalsum-s1)));
		}
	} 
	return mini;
	// Write your code here.
}
