class Solution {
public:

    void dfs(int node, vector<int>&vis, vector<int>adj[]) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it,vis,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        // create a adj list;
        vector<int>adj[v];
    
        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[i].size(); j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // call dfs and for every start node keep the count;
        int count = 0;
        vector<int>vis(v,0);

        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};