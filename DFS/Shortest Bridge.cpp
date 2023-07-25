class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, queue<pair<int,int>>& q, int drow[], 
            int dcol[]) {
        vis[row][col] = 1;
        q.push({row,col});

        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && !vis[nrow][ncol] && grid[nrow][ncol] == 1 ) {
                dfs(nrow,ncol,grid,vis,n,q,drow,dcol);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q;

        // dfs to insert all the connected indexs which forms a island
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1}; 

        bool found = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,grid,vis,n,q,drow,dcol);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

        // multisurce dfs keep on increasing the size of island asap we found another one return the step
        int step = 0;
        while(!q.empty()) {
            int s = q.size();
            while(s-- > 0) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i=0; i<4; i++) {
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];

                    if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && !vis[nrow][ncol]) {
                        if(grid[nrow][ncol] == 1) return step;
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }

                }
            }
            step++;
        }
        return -1;
    }
};