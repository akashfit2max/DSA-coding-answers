class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  {
            return s;
        }
        
        string ans="";
        
        for(int r=0;r<numRows;r++) {
            int inc = 2*(numRows-1);
            for(int j=r;j<s.length();j+=inc) {
                ans+=s[j];
                if(r>0 && r<numRows-1 &&  j+inc-2*r < s.length()) {
                    ans+=s[j+inc-2*r];
                }
            }
        }
        return ans;
    }
};





class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>ans(numRows);
        bool flag = false;
        int i = 0;

        for(auto ch : s) {
            ans[i] += ch;
            if(i==0 || i == numRows-1) {
                flag = !flag;
            }
            if(flag) {
                i++;
            }
            else {
                i--;
            }
        }
        string zigzag = "";
        for(auto str : ans) {
            zigzag += str;
        }
        return zigzag;
    }
};