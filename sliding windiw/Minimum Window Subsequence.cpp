class Solution {
  public:
    string minWindow(string s, string t) {
        // Write your Code here
        int j = 0;
        int minWin = INT_MAX;
        int start = -1;
        
        for(int i=0; i<s.length(); i++) {
            // if the char are same increment the j pointer
            if(s[i] == t[j]) {
                j++;
            }
            
            // if we finally reach end of the string T, we can start shrinking our window
            if(j==t.length()) {
                j--;
                // we are doing j-- in order to minimize our win size
                int end = i;
                while(j >=0) {
                    if(s[i] == t[j]) {
                        j--;
                    }
                    i--;
                }
                
                i++;
                j++;
                // increment i and j for next iteration
                if(end-i+1 < minWin) {
                    minWin = end-i+1;
                    start = i;
                }
            }
        }
        
        return minWin == INT_MAX ? "" : s.substr(start,minWin);
    }
};