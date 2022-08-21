class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty() && s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
        }
        
        // if there are still some element in the stack
        while(!st.empty())
        {
            s.erase(st.top(),1);
            st.pop();
        }
        
        return s;
        
    }
};