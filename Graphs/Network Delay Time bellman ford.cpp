class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        for(int i=0; i<n-1; i++) {
            for(auto it : times) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v] ) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        int maxwait = 0;
        for (int i = 1; i <= n; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};