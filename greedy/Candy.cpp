class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>ans(n,1);
        for(int i=1; i<n; i++) {
            if(ratings[i] == ratings[i-1]) continue;
            if(ratings[i] > ratings[i-1]) {
                ans[i] = 1 + ans[i-1];
            }
        }
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                if(ans[i] <= ans[i+1]) {
                    ans[i] = 1 + ans[i+1];
                }
            }
        }
        int sum = 0;
        for(auto it : ans) {
            sum += it;
        }
        return sum;
    }
};