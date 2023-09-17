class Solution {
public:
    vector<int> partitionLabels(string st) {
        unordered_map<char,int>mp;
        for(int i=0; i<st.length(); i++) {
            mp[st[i]] = i;
        }
        int s=0,e=0;
        int maxi = INT_MIN;
        vector<int>ans;
        while(s < st.length() && e < st.length()) {
            maxi = max(maxi,mp[st[e]]);
            // cout<<e<<" ";
            if(e==maxi) {
                // cout<<e<<" akas";
                ans.push_back(e-s+1);
                s=e+1;
            }
            e++;
        }
        return ans;
    }
};