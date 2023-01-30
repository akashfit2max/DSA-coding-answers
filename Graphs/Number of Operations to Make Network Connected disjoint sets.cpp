// using disjoint sets
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
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // traverse the edges
        DisjointSet ds(n);
        int cntExtraEdges = 0;
        for(auto it : connections) {
            int u = it[0];
            int v = it[1];

            // if the Ultimate parent of u and v are some then they are extra edges
            if(ds.findUPar(u) == ds.findUPar(v)) {
                cntExtraEdges++;
            }
            else {
                ds.unionBySize(u,v);
            }
        }

        // count the no. of components in the graph
        int cntComp=0;
        for(int i=0; i<n; i++) {
            // we can do this by simply checking the no of ultimate parent that point to itself
            if(ds.parent[i] == i) {
                cntComp++;
            }
        }

        // the min no of op would be cntComp-1;
        int ans = cntComp-1;
        if(cntExtraEdges >= ans) {
            return ans;
        }
        else {
            return -1;
        }
    }
};