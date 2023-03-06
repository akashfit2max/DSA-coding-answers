#include <bits/stdc++.h>
int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp) {
    // pick lengths & sum up to make it N
    //base case
    if(ind == 0) {
        // as the rod len is 1 we mul the price by N
        return N*price[0];
    }
    if(dp[ind][N] != -1) return dp[ind][N];
    int not_pick = 0 + f(ind-1,N,price,dp);
    int pick = INT_MIN;
    int rodLen = ind+1;
    if(rodLen <= N) {
        pick = price[ind] + f(ind,N-rodLen,price,dp);
    }
    return dp[ind][N] = max(pick,not_pick);
}
int cutRod(vector<int> &price, int N)
{
    // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    // return f(n-1,n,price,dp);

    // tabulation
   vector<vector<int>> dp(N,vector<int>(N+1,0));
    
    for(int i=0; i<=N; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];
}
