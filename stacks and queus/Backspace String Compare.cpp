class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;

        for(auto it : s) {
            if(!s1.empty() && it == '#') {
                s1.pop();
            }
            else if(it != '#') s1.push(it);          
        }

        for(auto it : t) {
            if(!s2.empty() && it == '#') {
                s2.pop();
            }
            else if(it != '#') s2.push(it);
        }

        s.clear();
        while(!s1.empty()) {
            s += s1.top();
            s1.pop();
        }

        t.clear();
        while(!s2.empty()) {
            t += s2.top();
            s2.pop();
        }
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());

        cout<<s<<"----"<<t;
        return s==t;
    }
};