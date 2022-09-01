class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            c += nums[i]-nums[0];
        }
        
        return c;
    }
};