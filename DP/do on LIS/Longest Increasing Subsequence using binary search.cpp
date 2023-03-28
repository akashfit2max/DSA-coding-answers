class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                auto ind = lower_bound(temp.begin(),temp.end(), nums[i]);
                *ind = nums[i];
            }
        }
        return temp.size();
    }
};