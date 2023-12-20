class Solution {
public:
    vector<int> countBits(int n) {
        // keep storing the bits of prev num and just add 1 to the ans as when we do n & n-1 there is only 1 bit difference
        vector<int>ans(n+1,0);
        for(int i=1; i<=n; i++) {
            ans[i] = ans[i & (i-1)] + 1;
        }

        return ans;
    }
};