class Solution {

private:
    bool dfs(int node, int vis[], int pathVis[], vector<vector<int>>& graph, int check[]) {
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        
        for(auto it : graph[node]) {
            // if node is not visited
            if(!vis[it]) {
                if(dfs(it,vis,pathVis,graph,check)) {
                    return true;
                }
            }
            // if visited it has to be in the same path
             else if (pathVis[it]) {
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        int vis[10000] = {0};
        int pathVis[10000] = {0};
        int check[10000] = {0};
        vector<int>safe_nodes;
        for(int i=0; i<v; i++) {
           if(!vis[i]) {
                dfs(i,vis,pathVis,graph,check);
           }
        }
        
        for(int i=0; i<v; i++) {
            if(check[i]) {
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
    }
};