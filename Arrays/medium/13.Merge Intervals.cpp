class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(intervals.begin(),intervals.end());
        
        vector<int>temp = intervals[0];
        
        for(auto it : intervals)
        {
            // if the temp interval 2nd 1st element is greater than the coming interval 1st ele
            if(it[0] <= temp[1] )
            {
                temp[1] = max(it[1],temp[1]);
            }
            else 
            {
                ans.push_back(temp);
                temp = it;
            }
                
        }
        ans.push_back(temp);
        return ans;
    }
};