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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // first we need the last stone in the row and col
        // to get the dimentions 
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        // create a disjoint set
        DisjointSet ds(maxRow+maxCol+1);
        //set to store the nodes in which stones are present
        set<int>s;
        for(auto it : stones) {
            // the row and col were stones are present
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow,nodeCol);
            s.insert(nodeRow);
            s.insert(nodeCol);
        }

        // get the count of the connectd comp
        int cnt = 0;
        for(auto it : s) {
            if(ds.findUPar(it) == it) {
                cnt++;
            }
        }

        return n-cnt;
    }
};