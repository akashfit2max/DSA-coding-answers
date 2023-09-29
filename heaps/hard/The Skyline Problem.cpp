class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>>result;
        vector<pair<int,int>>points;

        // storing in pairs {start,ending} - {2,-10},{9,10} - -ve ending +ve starting
        for(int i=0; i<b.size(); i++) {
            int height = b[i][2];
            int start = b[i][0];
            int end = b[i][1];

            points.push_back({start,-height});
            points.push_back({end,height});
        }

        // sorting in asec order
        sort(points.begin(), points.end(), cmp);

        // store element in asce order
        multiset<int>s;
        s.insert(0);
        int curr_height = 0;

        for(auto x : points) {
            // starting point h
            if(x.second < 0) {
                s.insert(-1*x.second);
                int max_height = *s.rbegin();
                if(curr_height != max_height) {
                    curr_height = max_height;
                    result.push_back({x.first,curr_height});
                }
            }
            // ye ending point he ynha set ye values hatani h aur next greatest in set dhundna h 
            else {
                // remove from set
                auto it = s.find(x.second);
                s.erase(it);

                // element hatane k baad next max nikalo aur check kro curr height se agar match ho raha skip wrna insert in ans
                int max_height = *s.rbegin();
                if(curr_height != max_height) {
                    curr_height = max_height;
                    result.push_back({x.first,curr_height});
                }
            }
        }
        return result;
    }
};