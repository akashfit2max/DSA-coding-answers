class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>>vis(r,vector<int>(c,0));
        // min heap to store the min boundary height along with indices
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;

        int vol = 0;

        // traverse from the boundary and keep reducing the boundary
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i==0 || i==r-1 || j==0 || j==c-1) {
                    pq.push({grid[i][j],{i,j}});
                    vis[i][j] = true;
                }
            }
        }

        int minBdht = 0;

        while(!pq.empty()) {
            // get the min height
            int currHt = pq.top().first;
            int cr = pq.top().second.first;
            int cc = pq.top().second.second;
            minBdht = max(minBdht,currHt);

            pq.pop();

            int drow[] = {-1,0,+1,0};
            int dcol[] = {0,+1,0,-1}; 

            for(int i=0; i<4; i++) {
                int nr = cr + drow[i];
                int nc = cc + dcol[i];

                if(nr >= 0 && nr < r && nc >=0 && nc < c && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    pq.push({grid[nr][nc],{nr,nc}});
                    
                    // add it the grid value is less than min bhd
                    if(grid[nr][nc] < minBdht) {
                        vol += minBdht - grid[nr][nc];
                    }
                }
            }
        }

        return vol;
    }
};