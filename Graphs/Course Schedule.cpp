class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<int>ind(numCourses,0);

        //create a indgree array
        for(int i=0; i<numCourses; i++) {
            for(auto it : adj[i]) {
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++) {
            if(ind[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()) {
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it : adj[node]) {
                ind[it]--;
                if(ind[it] == 0) {
                    q.push(it);
                }
            }
        }

        return numCourses == cnt;
    }
};