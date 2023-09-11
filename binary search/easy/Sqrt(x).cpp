class Solution {
public:
    int f(int s, int e, int num) {
        int ans = 0;
        while(s <= e) {
            int m = s + (e-s)/2;
            if(m*m == num) {
                return m;
                }
                else if(m*m > num) {
                    e = m-1;
                }
                else {
                    ans = m;
                    s = m+1;
                }
            }
        return floor(ans);
    }
    int mySqrt(int x) {
        return f(1,x,x);
    }
};