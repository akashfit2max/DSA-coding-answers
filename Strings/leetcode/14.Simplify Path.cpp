#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        path = path+"/";
        string curr="";
        
        for(auto p : path)
        {
            if(p=='/')
            {
                if(!s.empty() && curr=="..")
                {
                    s.pop();
                }
                else if(curr != "" && curr != "." && curr!="..")
                {
                    s.push(curr);
                }
                
                curr = "";
            }
            else
            {
                curr+=p;
            }
        }
        
        string ans;
        while(!s.empty())
        {
           ans = "/"+s.top()+ans;
            s.pop();
        }
        
        if(ans.size()==0)
        {
            ans="/";
        }
        
        return ans;
    }
};