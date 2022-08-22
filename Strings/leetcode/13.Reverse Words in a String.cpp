class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ') continue;
            string str;
            while(i<s.length() && s[i]!=' ')
            {
                str+=s[i];
                i++;
            }
            st.push(str);
        }
        
        string res;
        
        while(!st.empty())
        {
            if(st.size()>1)
            {
                 res+=st.top()+" ";
            }
           else
           {
               res+=st.top();
           }
            st.pop();
        }
        return res;
    }
};