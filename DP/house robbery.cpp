class Solution {
private:
    int findSum(vector<int>&temp) {
        int n = temp.size();
        int prev = temp[0];
        int prev2 = 0;
        for(int i=1;i<n;i++) {
            int take = temp[i];
            if(i>1) {
                take += prev2;
            }
            int not_take = 0 + prev;
            int curr = max(take,not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
       // find the max sum without adj leaving the first and last ele
       vector<int>temp1,temp2;
       int n = nums.size();
       if(n==1) return nums[0];
       for(int i=0; i<n; i++) {
           if(i!=0) temp1.push_back(nums[i]);
           if(i!=n-1) temp2.push_back(nums[i]);
       }

       return max(findSum(temp1),findSum(temp2));
    }
};