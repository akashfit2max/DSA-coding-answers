class Solution {
private:
    int f(int i, int j, vector<int>& cuts,vector<vector<int>>&dp) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<=j; k++) {
            int cost = cuts[j+1]-cuts[i-1] + f(i,k-1,cuts,dp) + f(k+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int s = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin() , cuts.end());
        // vector<vector<int>>dp(s+1,vector<int>(s+1,-1));
        // return f(1,s,cuts,dp);
        // tabulation
        vector<vector<int>>dp(s+2,vector<int>(s+2,0));
        //base case will not occur
        for(int i=s; i>=1; i--) {
            for(int j=1; j<=s; j++) {
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k=i; k<=j; k++) {
                    int cost = cuts[j+1]-cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini,cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][s];
    }
};