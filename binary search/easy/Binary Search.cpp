class Solution {
public:
    int f(int s, int e, int target,vector<int>& nums) {
        while(s <= e) {
            int m = s + (e-s)/2;
            if(nums[m] == target) {
                return m;
            }
            else if(nums[m] > target) {
                e = m-1;
            }
            else {
                s = m+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return f(0,n-1,target,nums);
    }
};