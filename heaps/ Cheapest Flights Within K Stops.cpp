class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // using dijkstra algo
        vector<pair<int,int>>adj[n];
        for(auto it : flights) {
            // {from,{to,dist}}
            adj[it[0]].push_back({it[1],it[2]});
        }
        // {stop,{node,dist}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src] = 0;

        while(!q.empty()) {
            int node = q.front().second.first;
            int cost = q.front().second.second;
            int stop = q.front().first;
            q.pop();

            if(stop > k) continue;

            for(auto it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if(wt + cost < dist[adjnode] && stop <= k) {
                    dist[adjnode] = cost + wt;
                    q.push({stop+1,{adjnode,cost+wt}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }   
};