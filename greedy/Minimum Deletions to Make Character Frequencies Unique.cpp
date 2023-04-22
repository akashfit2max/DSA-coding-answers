class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto & it : s) {
            freq[it-'a']++;
        }
        unordered_set<int>st;
        int cnt = 0;
        for(int i=0; i<26; i++) {
            while(!st.empty() && st.count(freq[i]) && freq[i] > 0) {
                cnt++;
                freq[i]--;
            }
            st.insert(freq[i]);
        }
        return cnt;
    }
};