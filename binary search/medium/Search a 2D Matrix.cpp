class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int l=0, h = (r*c)-1;
        while(l <= h) {
            int m = l + (h-l)/2;
            int i = m/c;
            int j = m%c;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) {
                h = m-1;
            }
            else {
                l = m + 1;
            }
        }
        return false;
    }
};