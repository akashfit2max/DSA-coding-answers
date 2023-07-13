class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int prev_end = INT_MIN;
        sort(intervals.begin(),intervals.end());
        for(auto &interval : intervals) {
            if(interval[0] >= prev_end) {
                //non-overlap
                prev_end = interval[1];
            }
            else {
                // overlap
                cnt++;
                prev_end = min(prev_end,interval[1]);
            }
        }
        return cnt;
    }
};