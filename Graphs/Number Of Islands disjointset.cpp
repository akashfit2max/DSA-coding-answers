//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
  private:
    bool isValid(int nrow, int ncol, int n ,int m) {
        return nrow >=0 && nrow < n; ncol >=0 && ncol < m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // create a disjoint set object for m*n matrix
        DisjointSet ds(n*m);
        // create a vis array to mark the nodes visited
        int vis[n][m];
        memset(vis,0,sizeof vis);
        // to count the connected comp in every step
        vector<int>ans;
        int cnt = 0;
        for(auto it : operators) {
            int r = it[0];
            int c = it[1];
            
            //if they are vis already keep the cnt as same and move to next set of node
            if(vis[r][c]) {
                ans.push_back(cnt);
                continue;
            }
            // if not visited make them visited and inc the count
            vis[r][c] = 1;
            cnt++;
            
            // now check the all 4 direction and reduce the count if they are connected
            int delrow[] = {-1,0,+1,0};
            int delcol[] = {0,+1,0,-1};
            
            for(int i=0; i<4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(isValid(nrow,ncol,n,m) && vis[nrow][ncol]) {
                    // now check the connection using the findUPar if they are not equal there is a connection
                    int node = r*m + c;
                    int adjNode = nrow*m + ncol;
                    if(ds.findUPar(node) != ds.findUPar(adjNode)) {
                        cnt--;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends