class Solution {
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // using dijkstra algorith
        //create a pq min-heap
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();

        // create a dist array to store the min diff
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        // {diff,{row,col}}
        pq.push({0,{0,0}});

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r==n-1 && c==m-1) return diff;
            
            // going all four direction
            for(int i=0; i<4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(isValid(nrow,ncol,n,m)) {
                    int newEffor = max(diff, abs(heights[r][c] - heights[nrow][ncol]));
                    if(newEffor < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffor;
                        pq.push({newEffor,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};