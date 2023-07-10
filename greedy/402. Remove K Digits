class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k) return "0";
        if(k==0) return num;
        stack<char>s;
        for(auto &it : num) {
            while(!s.empty() && s.top() > it && k>0) {
                s.pop();
                k--;
            }
            s.push(it);
            // removing preceding zeros
            if(s.size()==1 && it == '0') s.pop();
        }
        while(k && !s.empty()) {
            --k;
            s.pop();
        }
        string ans = "";
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans == "" ? "0" : ans;
    }
};
