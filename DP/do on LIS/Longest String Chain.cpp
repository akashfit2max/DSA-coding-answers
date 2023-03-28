class Solution {
public: 
    bool checkPossible(string &s1, string &s2) {
        if(s1.size() != s2.size()+1) return false;
        int f = 0;
        int s = 0;
        while(f < s1.size()) {
            if(s1[f] == s2[s] && s < s2.size()) {
                f++;
                s++;
            }
            else {
                f++;
            }
        }
        if(f==s1.size() && s == s2.size()) return true;
        return false;
    }

    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int  n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(), words.end(), comp);
        int maxi = INT_MIN;
        for(int i=0; i<=n-1; i++){
            for(int p = 0; p <=i-1; p ++){
                if(checkPossible(words[i],words[p]) && 1 + dp[p] > dp[i]){
                    dp[i] = 1 + dp[p];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }

};