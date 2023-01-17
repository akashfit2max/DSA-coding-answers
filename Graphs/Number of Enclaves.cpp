int delrow[] = {-1,0,+1,0};
int delcol[] = {0,+1,0,-1};
class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>& grid, int n, int m) {
        vis[row][col] = 1;

        for(int i=0; i<4; i++) {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow,ncol,vis,grid,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // first row, first col, last row, last col
                if(i==0 || j==0 || i==n-1 || j==m-1) {
                    if(!vis[i][j] && grid[i][j] == 1) {
                        dfs(i,j,vis,grid,n,m);
                    }
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};