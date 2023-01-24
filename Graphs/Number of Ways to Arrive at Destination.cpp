class Solution{
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        //{node,time}
        vector<pair<ll,ll>> adj[n+10];
        for(auto it:roads){
            adj[ll(it[0])].push_back({ll(it[1]),ll(it[2])});
            adj[ll(it[1])].push_back({ll(it[0]),ll(it[2])});
        }
        //{distance,node}
        priority_queue<pair<ll, ll>,
        vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        //two vectors created , distance and ways
        vector<ll> dist(n,LLONG_MAX), ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                ll adjNode= it.first;
                ll edW= it.second;
                //comes for first time with min weight(i.e time here)
                if(dis+edW< dist[adjNode]){
                    dist[adjNode]=dis + edW;
                    ways[adjNode]=ways[node];
                    pq.push({dis+edW, adjNode});
                }
                //comes to node again with min distance
                else if(dis+edW==dist[adjNode]){
                    //dont add to pq , just increase the count of ways 
                    ways[adjNode]+=(ways[node])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
    }
};