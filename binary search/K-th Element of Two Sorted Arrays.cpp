#include <bits/stdc++.h>
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
        if(n1 > n2) return kthElement(b,a,n2,n1,k);
        int left = k;
        int n = n1 + n2;
        

        int l = max(0,k-n2), h = min(k,n1);

        while( l <= h) {
            int m1 = (l + h) >> 1;
            int m2 = left - m1;

            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if(m1 < n1) r1 = a[m1];
            if(m2 < n2) r2 = b[m2];
            if(m1-1 >=0) l1 = a[m1-1];
            if(m2-1 >=0) l2 = b[m2-1];

            if(l1 <= r2 && l2 <= r1) {
                return max(l1,l2); 
            }
            else if ( l1 > r2) {
                h = m1-1;
            }
            else {
                l = m1 + 1;
            }
        }
        return 0;
}