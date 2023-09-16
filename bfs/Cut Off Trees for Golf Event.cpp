class Solution {
public:
    int drow[4] = {-1,0,+1,0};
    int dcol[4] = {0,+1,0,-1}; 
    int vis[55][55];

    void clearMat() {
        for(int i=0; i<55; i++) {
            for(int j=0; j<55; j++) {
                vis[i][j] = 0;
            }
        }
    }

    bool isValid(int i, int j, vector<vector<int>>& forest) {
        return i >=0 && i < forest.size() && j >=0 && j < forest[0].size();
    }

    int bfs(vector<vector<int>>& forest,int i, int j, int lr, int lc) {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{i,j}});

        while(!q.empty()) {
            int lvl = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            vis[r][c] = 1;
            q.pop();
            if(r==lr && c==lc) return lvl;

            for(int i=0; i<4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(isValid(nr,nc,forest) && !vis[nr][nc] && forest[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({lvl+1,{nr,nc}});
                }
            }
        }
        return -1;

    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        // idea is to do a dfs to find the no. of steps need to reach from 1st smallet tree to the next smaller then the next smaller ....
        vector<pair<int,pair<int,int>>>v;
        int n = forest.size();
        int m = forest[0].size();

        // storing forest
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(forest[i][j] > 1) {
                    v.push_back({forest[i][j] , {i,j}});
                }
            }
        }

        // sort them to cut from small to large
        v.push_back({0,{0,0}});
        sort(v.begin(),v.end());
        

        int ans = 0;
        for(int i=0; i<v.size()-1; i++) {
            clearMat();
            int k = bfs(forest,v[i].second.first,v[i].second.second,v[i+1].second.first,v[i+1].second.second);
            if(k == -1) return -1;
            ans += k;
        }
        return ans;
    }
};