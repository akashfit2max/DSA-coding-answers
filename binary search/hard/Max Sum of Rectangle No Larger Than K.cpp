class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        int c = matrix[0].size();
        int res = INT_MIN;
        for(int i = 0; i < c; i++) {
            vector<int>sums(r,0);
            for(int j = i; j < c; j++) {
                for(int k = 0; k < r; k++) {
                    sums[k] += matrix[k][j];
                }
                set<int>s = {0};
                int run_sum = 0;
                for(auto sum : sums){
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum-k);
                    if(it != s.end()) {
                        // get max sum
                        res = max(res , run_sum-*it);
                    }
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};


// tc - c*c*r*log(r)
// sc - O(r)