//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
     void topo(int node, int vis[], vector<pair<int,int>>adj[], stack<int>& s) {
         vis[node] = 1;
         
         //traverse adj nodes
         for(auto it : adj[node]) {
             int v = it.first;
             if(!vis[v]) {
                 topo(v,vis,adj,s);
             }
         }
         
         s.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        //vis array
        vector<pair<int,int>>adj[N];
        for(int i=0; i<M; i++) {
            for(auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                adj[u].push_back({v,wt});
            }
        }
        
        // do topo sort
        int vis[N] = {0};
        stack<int>s;
        
        for(int i=0; i<N; i++) {
            if(!vis[i]) {
                topo(i,vis,adj,s);
            }
        }
        
        //findin dist
        
        vector<int>dist(N);
        for(int i=0; i<N; i++) dist[i] = 1e9;
        dist[0] = 0;
        
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            
            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]) {
                    dist[v] = dist[node]+wt;
                }
            }
        }
        
         for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
      return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends