class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if( n == 1) return 1;

        int res = 0;
        // n * n * O(logN) = O(n2) 
        for(int i=0; i<n; i++) { // for each point
            unordered_map<string,int>mp;
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                auto gcd = __gcd(dy,dx);
                string key = to_string(dx/gcd) + "_" + to_string(dy/gcd);
                mp[key]++;
            }

            for(auto it : mp) {
                res = max(res,it.second+1);
            }
        }
        return res;
    }
};