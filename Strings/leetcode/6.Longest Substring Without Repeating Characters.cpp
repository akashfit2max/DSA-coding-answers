class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int left=0,right=0;
        int len=0;
        while(right < s.length())
        {
            // check where it is appeared last
            if(mp.find(s[right])!=mp.end())
            {
//                 move left to that pos if it is in the range l to r
                left = max(left,mp[s[right]]+1);
            }
            
//             store the index where it occured last
            mp[s[right]]=right;
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
};