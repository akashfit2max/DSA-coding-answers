class Solution {
public:
    int drow[4] = {-1,0,+1,0};
    int dcol[4] = {0,+1,0,-1}; 

    bool reachable(int t, vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c, int n) {
        if(r==n-1 && c==n-1) return true;

        vis[r][c] = 1;

        for(int i=0; i<4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[r][c] <= t && !vis[nr][nc] && grid[nr][nc] <= t) {
                if(reachable(t,grid,vis,nr,nc,n)) return true;
            }
        }

        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high = n*n-1;
        int ans = 0;
        while(low <= high) {
            int mid = low + (high-low)/2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(reachable(mid,grid,vis,0,0,n)) {
                ans= mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};