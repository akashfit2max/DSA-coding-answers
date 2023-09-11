class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = n-1, c=0, cnt = 0;
        while( r >= 0 && c < m) {
            if(grid[r][c] < 0) {
                --r;
                // all the elements towards right will be negative as they are sorted
                cnt += m-c;
            }
            else {
                c++;
            }
        }
        return cnt;
    }
};