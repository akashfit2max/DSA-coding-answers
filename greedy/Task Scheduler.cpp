class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        if(n == 0 ) {
            return s;
        }
        unordered_map<char,int>mp;
        for(auto it : tasks) {
            mp[it]++;
        }
        int max_occ = INT_MIN;
        for(auto it : mp) {
            max_occ = max(max_occ , it.second);
        }
        // cout<<max_occ<<"......";
        int k = 0;
        for(auto it : mp) {
            if(it.second == max_occ) {
                k++;
            }
        }
        // cout<<k;
        return max(s,(max_occ-1)*(n+1)+k);
        // return 0;
    }
};