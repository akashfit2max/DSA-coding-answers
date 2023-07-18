class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int s = ranges.size();
        int min = 0, max = 0;
        int open = 0;
        int idx = 0;
        while(max < n) {
            for(int i=idx; i<s; i++) {
                if(i-ranges[i] <= min && i + ranges[i] > max) {
                    max = i + ranges[i];
                    idx = i;
                }
            }
            if(min == max) return -1;
            open++;
            min = max;
        }
        return open;
    }
};