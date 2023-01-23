class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>adjRev[v];
        vector<int>ind(v,0);
        for(int i=0;i<v; i++) {
            for(auto it : graph[i]) {
                adjRev[it].push_back(i);
                ind[i]++;
            }
        }

        queue<int>q;
        for(int i=0; i<v ; i++) {
            if(ind[i]==0) {
                q.push(i);
            }
        }

        vector<int>safe;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(auto it : adjRev[node]) {
                ind[it]--;
                if(ind[it]==0) {
                    q.push(it);
                }
            }
        }

        sort(safe.begin(),safe.end());

        return safe;

    }
};