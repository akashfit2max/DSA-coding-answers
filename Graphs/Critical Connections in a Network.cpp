class Solution {
    int timer = 0;
private:
    void dfs(int node, int parent, vector<int>adj[], vector<int>&v, int tin[], int low[], vector<vector<int>>&bridges) {
        //make it visisted
        v[node]=1;
        // make the low and the times and inc it at every step
        low[node] = tin[node] = timer;
        timer++;

        for(auto it : adj[node]) {
            if(it == parent) continue;
            // not vis visit it
            if(!v[it]) {
                dfs(it,node,adj,v,tin,low,bridges);
                // once the dfs is complete
                low[node] = min(low[node],low[it]);
                // check if the tin of node is less than it adj node
                if(low[it] > tin[node]) {
                    bridges.push_back({it,node});
                }
            }
            else {
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create a ajd list
        vector<int>adj[n];
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //vis arrary
        vector<int>v(n,0);
        int tin[n]; //time of insertion
        int low[n]; //lowest time of insertion
        vector<vector<int>>bridges;
        dfs(0,-1,adj,v,tin,low,bridges);
        return bridges;
    }
};