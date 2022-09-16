class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 != 0) return {};
        // it cant be a double array as it is odd
        vector<int>ans;
        // to return the ans;
        sort(changed.begin(),changed.end());
        // sort the array
        unordered_map<int,int>mp;
        // to store the freq of the occuring elements
        for(auto& ele : changed)
        {
            mp[ele]++;
        }
        
        for(auto& y : changed)
        {
            if(mp[y]==0) continue;
            // if we have already decreased it's value when we were checking y/2 value, like 2,4 we will remove 4 also when we will check 2 but our iteration will come again on 4.
            if(mp[y*2]==0) return {};
            // if we have y but not y*2 return vacant array
            ans.push_back(y);
		    // if we have both y and y*2, store in our ans array
            mp[y]--;
		    // decrease the frequency of y and y*2
            mp[y * 2]--;
        }
        
        return ans;
    }
};