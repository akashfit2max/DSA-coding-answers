class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int max_freq = 0;
        int max_len = 0;
        int ws = 0;

        for(int we = 0; we < s.length(); we++) {
            mp[s[we]]++;

            max_freq = max(max_freq,mp[s[we]]);

            // shrinking the window
            while((we-ws+1) - max_freq > k) {
                mp[s[ws]]--;
                ws++;
            }

            max_len = max(max_len,we-ws+1);
        }
        return max_len;
    }
};