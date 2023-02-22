#include <bits/stdc++.h>
int f(int ind, int w,vector<int>&wt, vector<int>&val,vector<vector<int>>&dp)
{
	//base case
	if(ind == 0) {
		// at 0th ind it can only pick it wt[0] < w
		if(wt[0] <= w) return val[0];
		return 0;
	}
	if(dp[ind][w] != -1) return dp[ind][w];

	// explore all posibilities
	int not_take = 0 + f(ind-1,w,wt,val,dp);
	int take = INT_MIN;
	if(wt[ind] <= w) {
		take = val[ind] + f(ind-1,w-wt[ind],wt,val,dp);
	}

	return dp[ind][w] = max(not_take,take);

}
int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    //Base Condition
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}