class DisjointSet {
public: 
    vector<int> rank, parent, size; 
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
bool isValid(int i,int j,int n){
    if(i<0 || i>=n || j<0 || j>=n){
        return false;
    }

    return true;
}
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 0) continue;

                for(int idx=0;idx<4;idx++){
                    int newr = i + dx[idx];
                    int newc = j + dy[idx];

                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        int node = i*n + j;
                        int adjnode = newr*n + newc;

                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }

        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1) continue;

                set<int>set;

                for(int idx=0;idx<4;idx++){
                    int newr = i + dx[idx];
                    int newc = j + dy[idx];

                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        set.insert(ds.findUPar(newr*n + newc));
                    }
                }

                int totalsize = 0;

                for(auto it: set){
                    totalsize += ds.size[it];
                }
                mx = max(mx,totalsize + 1);
            }
        }

        mx=max(mx,ds.size[ds.findUPar(n*n-1)]);
        return mx;
    }
};