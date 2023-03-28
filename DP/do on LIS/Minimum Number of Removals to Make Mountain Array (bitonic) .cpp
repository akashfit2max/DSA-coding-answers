class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> m1(n,1),m2(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    m1[i]=max(m1[i],m1[j]+1);
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]<nums[i])
                    m2[i]=max(m2[i],m2[j]+1);
            }
        }
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
          if(m1[i]==1||m2[i]==1)
              continue;
          res=max(res,m1[i]+m2[i]-1);   
        }
        return(n-res);
    }
};