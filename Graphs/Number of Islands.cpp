class Solution {
private:
    void DFS(vector<vector<char>> &grid,int i,int j, vector<vector<int>> &vis){
        // base case
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || grid[i][j] != '1') return;

        vis[i][j] = 1;
        
        // Traversing 
        DFS(grid,i,j-1,vis); // left
        DFS(grid,i,j+1,vis); // right
        DFS(grid,i-1,j,vis); // up
        DFS(grid,i+1,j,vis); // down
        
    }
public:
    // Data members
    int n,m;
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        
        // count of islands
        int countIsland = 0;
        
        // making DFS traversal
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    countIsland++;
                    DFS(grid,i,j,vis);
                }
            }
        }
        
        return countIsland;
    }
};