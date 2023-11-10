class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n = s.length(), ans = 0;
        unordered_map<char,int>mp;
        for(; r < n ; r++) {
            mp[s[r]]++;
            for(; mp[s[r]] > 1; l++) {
                mp[s[l]]--;
            }
            ans = max(ans , r-l+1);
        }
        return ans;
    }

};