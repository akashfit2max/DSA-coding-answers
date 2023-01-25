class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // create a matrix to store the distance
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // pointing to itself
        for(int i=0; i<n; i++) dist[i][i] = 0;

        // floydwarshall algo
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    // if unreachable skip them
                    if(dist[i][k] == INT_MAX  || dist[k][j] == INT_MAX) {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }

        // to keep the min count of the cities
        int cntCity = n;
        // to get the city num
        int cityNum = -1;

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= cntCity) {
                cntCity = cnt;
                cityNum = i;
            }
        }
        return cityNum;
    }
};