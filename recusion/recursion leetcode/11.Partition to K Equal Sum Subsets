class Solution {
public:
    
    bool helper(int i, int bucketNum, int bucketSum, int reqSum, vector<int>&nums, vector<int>&alreadyPicked , int k)
    {
        if(bucketNum == k+1) return true;
        
        if(bucketSum == reqSum)
        {
            return helper(0,bucketNum+1,0,reqSum,nums,alreadyPicked,k);
        }
        
        if(bucketSum > reqSum) return false;
        if(i >= nums.size()) return false;
        
        if(alreadyPicked[i] == 1)
        {
            return helper(i+1,bucketNum,bucketSum,reqSum,nums,alreadyPicked,k);
        }
        else
        {
//             pick the element 
            bucketSum+=nums[i];
            alreadyPicked[i] = 1;
            bool op1 = helper(i+1,bucketNum,bucketSum,reqSum,nums,alreadyPicked,k);
            
//             skip the element
            bucketSum-=nums[i];
            alreadyPicked[i] = 0;
            bool op2 = helper(i+1,bucketNum,bucketSum,reqSum,nums,alreadyPicked,k);
            
            return op1 || op2;
        }
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N=nums.size();

        //  If K is 1, then complete array will be our answer
        if (k==1) return true;

        //  If total number of partitions are more than N, then division is not possible
        if (N < k) return false;
        int sum=0;
        for(auto num : nums)
        {
            sum+=num;
        }
        if(sum%k != 0) return false;
        int reqSum = sum/k;
        vector<int>alreadyPicked(nums.size(),0);
        return helper(0,1,0, reqSum, nums,alreadyPicked,k);
    }
};