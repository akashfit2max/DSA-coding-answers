class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int s = 0, e = 0, count=0;
        while(e < nums.size()) {
            mp[nums[e]]++;
            while(mp.size() > k) {
                mp[nums[s]]--;
                if(mp[nums[s]] == 0) {
                    mp.erase(nums[s]);
                }
                s++;
            }
            count += (e-s+1);
            e++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmost(nums,k) - atmost(nums,k-1);
    }
};