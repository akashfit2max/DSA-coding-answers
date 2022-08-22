class Solution {
public:
    
    void generate(string t, int open, int close, vector<string>&ans, int n)
    {
        if(t.length()==n*2)
        {
            ans.push_back(t);
            return;
        }
        if(open < n)
        {
            generate(t+'(',open+1,close,ans,n);
        }
        if(close < open)
        {
            generate(t+')',open,close+1,ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate("",0,0,ans,n);
        return ans;
    }
};