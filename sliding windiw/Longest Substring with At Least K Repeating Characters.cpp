class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) {
            m[s[i]]++;
        }
        int indx = 0;
        // keep tracking the char which has freq >= k then do partition
        while(indx<n && m[s[indx]]>=k) indx++;
        if(indx == n) return n;
        int left = longestSubstring(s.substr(0,indx),k);
        int right = longestSubstring(s.substr(indx+1,n),k);
        return max(left,right);
    }
};