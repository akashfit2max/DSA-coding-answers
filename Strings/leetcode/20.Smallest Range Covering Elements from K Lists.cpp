class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>a;
        for(int i=0;i<nums.size();i++)
        {
            for(auto num : nums[i])
            {
                // [4,10][12,34][34,12] - [4,1][10,1][12,2][34,2][34,3].. etc etc
                a.push_back({num,i}); 
            }
        }
        
        sort(a.begin(),a.end());
        
        int mini = INT_MAX;
        int diff = nums.size();
        int total=0;
        vector<int>mp(diff,0);
        vector<int>ans;
        int j=0,i=0;
        
        while(i < a.size())
        {
            mp[a[i].second]++;
            if(mp[a[i].second]==1) total++;
            
            if(total==diff)
            {
                if(a[i].first-a[j].first+1 < mini)
                {
                    mini = a[i].first-a[j].first+1;
                    ans = {a[j].first,a[i].first};
                }
            }
            
            if(total == diff)
            {
                while(total==diff)
                {
                    if(mp[a[j].second] > 1)
                    {
                        mp[a[j].second]--;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(a[i].first-a[j].first+1 < mini)
                {
                    mini = a[i].first-a[j].first+1;
                    ans = {a[j].first,a[i].first};
                }
            }
            
            i++;
        }
        
        return ans;
    }
};