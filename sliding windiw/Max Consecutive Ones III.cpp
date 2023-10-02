class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int count_zero = 0, ans = 0;
        for(; r < n; r++) {
            if(nums[r] == 0) {
                count_zero++;
            }
            while(count_zero > k) {
                if(nums[l] == 0) {
                    count_zero--;
                }
                l++;
            }
            ans = max(ans , r-l+1);
        }
        return ans;
    }
};