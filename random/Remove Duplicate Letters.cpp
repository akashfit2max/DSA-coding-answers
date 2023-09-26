class Solution {
public:
    string removeDuplicateLetters(string s) {
        // monotonic inc stack + freq map + vis array
        stack<int>st;
        vector<int>freq(26,0);
        vector<bool>vis(26,false);

        // store the freq of all char
        for(auto ch : s) {
            freq[ch-'a']++;
        }

        // loop in string and create a monotonic stack
        for(auto ch : s) {
            // check if vis
            if(vis[ch-'a']) {
                // reduce the freq and continue
                freq[ch-'a']--;
                continue;
            }

            // loop for monotonic inc stack 
            while(!st.empty() && st.top() > ch && freq[st.top()-'a'] > 0) {
                vis[st.top()-'a'] = false;
                st.pop();
            }

            st.push(ch);
            freq[ch-'a']--;
            vis[ch-'a'] = true;
        }


        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};