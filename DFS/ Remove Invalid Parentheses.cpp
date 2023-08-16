class Solution {
public:

    int getMinInvalid(string s)
    {
        int i=0;
        stack<char>st;
        while(i < s.size())
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else if(s[i]==')')
            {
                if(st.size() > 0 && st.top()=='(')
                {
                    st.pop();
                }
                else {
                    st.push(')');
                }
            }
            i++;
        }
        
        return st.size();
    }
    
    unordered_map<string,int>mp;
    vector<string>res;
    void solve(string s, int minInv)
    {
        if(mp[s]!= 0)
        {
           return;
        }
        else {
            mp[s]++;
        }
        //base case
        if(minInv < 0)
        {
            return;
        }
        
        if(minInv == 0)
        {
            if(!getMinInvalid(s))
            {
                res.push_back(s);
                return;
            }
        }
        
        for(int i=0;i<s.size();i++)
        {
            // as we removed one paremthesis
            string l = s.substr(0,i);
            string r = s.substr(i+1);
            solve(l+r,minInv-1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        solve(s,getMinInvalid(s));
        return res;
    }
};