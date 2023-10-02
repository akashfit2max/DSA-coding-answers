class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& gru, int m) {
        int l = 0, r = 0, n = cus.size();
        int grumpy_cust = 0;
        int ans = 0;
        for(; r < n ; r++) {
            if(gru[r] == 1) {
                // if the cus is grump
                grumpy_cust += cus[r];
            }

            // once it reaches the window size i.e the min
            if(r-l+1 == m) {
                ans = max(ans,grumpy_cust);
                if(gru[l] == 1) {
                    grumpy_cust -= cus[l];
                }
                l++;
            }
        }

        for(int i=0; i<n; i++) {
            if(gru[i] == 0) {
                ans += cus[i];
            }
        }
        return ans;
    }
};