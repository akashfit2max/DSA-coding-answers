class Solution {
public:
    int getSplits(vector<int>& nums, int k, int splitSize) {
        int split = 1;
        int sum = 0;
        for(auto num : nums) {
            if(sum + num <= splitSize) {
                sum += num;
            }
            else {
                split++;
                sum = num;
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        while( low <= high) {
            int mid = low + (high-low)/2;
            int splits = getSplits(nums,k,mid);

            if(splits <= k) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};