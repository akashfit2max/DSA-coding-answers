class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        int i=0, j=0, ind=0;
        while(i<h && j<n){
            ind = i;
           while(i<h && j<n && haystack[i] == needle[j]) {
               
               i++;
               j++;
           }
           if( j >= n) return ind;
           else {
               j=0;
               i = ind+1;
           }
            
        }
        return -1;
    }
};