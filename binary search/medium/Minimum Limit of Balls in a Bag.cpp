class Solution {
public:
    bool isPossible(vector<int>& nums, int balls, int maxOperations) {
      int op = 0;
      for(int i=0; i<nums.size(); i++) {
        int operations = (nums[i]-1)/balls;
        op += operations;
        
      }
      if(op > maxOperations) {
          return false;
        }
      return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int h = *max_element(nums.begin(), nums.end());
        int ans = h;
        while(l <= h) {
          // m is the max balls in a bag we can keep
          int m = l + (h-l)/2;
          // in this we will check if this is possible
          if(isPossible(nums,m,maxOperations)) {
            ans = m;
            h = m-1;
          }
          else {
            l = m+1;
          }
        }
        return ans;
    }
};