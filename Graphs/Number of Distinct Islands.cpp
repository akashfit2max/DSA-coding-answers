//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int delrow[] = {-1,0,+1,0};
int delcol[] = {0,+1,0,-1};
class Solution {

private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int row0, int col0, queue<pair<int,int>>q, vector<pair<int,int>>& vec ) {
        vis[row][col] = 1;
        q.push({row,col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vec.push_back({r-row0, c-col0});
            for(int i=0; i<4; i++) {
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];
                
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
  
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int,int>>vec;
                    bfs(i,j,vis,grid,i,j,q,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends