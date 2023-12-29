class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>h;

        // store left in +ve
        // store right in -ve

        for(auto& it : buildings) {
            h.push_back({it[0],-it[2]});
            h.push_back({it[1],it[2]});
        }

        // sort them
        sort(h.begin(),h.end());

        int prev = 0, curr = 0;
        multiset<int>s;
        vector<vector<int>>res;
        s.insert(0);
        for(auto& it : h) {
            if(it.second < 0) {
                s.insert(-it.second);
            }
            else {
                // ending of a building
                s.erase(s.find(it.second));
            }

            // getting the latest element from multiset
            curr = *s.rbegin();

            if(prev != curr) {
                res.push_back({it.first,curr});
                // change prev to curr for the next building
                prev = curr;
            }
        }

        return res;
    }
};