class Solution {
public:
    //  recursive function
    int f(int i, int j1, int j2, vector<vector<int>>& grid, int r, int c,  vector<vector<vector<int>>>&dp) {
        //base case
        // 1 - out of bound
        // 3 direction = (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1)
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e8;
        // 2 - when you reach the destination
        if(i==r-1) {
            // you have 2 condition
            // 1 - if both of them comes to same cell - add only once
            if(j1 == j2) return grid[i][j1];
            // 2 - else they come in diff cell
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        // explore all paths
        // total there will be 9 paths 3*3
        // j values goes as -1,0,1
        int maxi = -1e8;
        for(int dj1=-1; dj1<=+1; dj1++) {
            for(int dj2=-1; dj2<=+1; dj2++) {
                // explore all path
                //same as base case 2 condition
                int value = 0;
                if(j1==j2) {
                    value += grid[i][j1];
                }
                else {
                    value += grid[i][j1] + grid[i][j2];
                }
                value += f(i+1,j1+dj1, j2+dj2, grid,r,c,dp);
                maxi = max(maxi , value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // using recursion
        // {i,j1,j2} 
        // j1 - robot 1
        // j2 - robot 2
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c, vector<int>(c,-1)));
        return f(0,0,c-1,grid,r,c,dp);
    }
};