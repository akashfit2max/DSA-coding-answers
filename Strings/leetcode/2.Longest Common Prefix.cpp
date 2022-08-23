class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string fst = strs[0];
        string end = strs[n-1];
        for(int i=0;i<fst.length();i++) {
            if(fst[i]==end[i]) {
                ans+=fst[i];
            }
            else {
                break;
            }
        }
        return ans;
    }
};
