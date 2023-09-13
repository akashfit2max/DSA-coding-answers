class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long  a = abs(dividend);
        long long b = abs(divisor);
        int res = 0;

        while(b <= a) {
            long long  sum = b, c=1;
            while(sum <= a-sum) {
                sum += sum;
                c += c;
            }
            res += c;
            a -= sum;
        }
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) return -res;
        return res;
    }
};











class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long  a = abs(dividend);
        long long b = abs(divisor);
        int res = 0;

        while(a-b >= 0) {
            int x = 0;
            while( a - (b<<1<<x) >= 0) {
                x++;
            }
            res += 1<<x;
            a -= b<<x;
        }
        
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) return -res;
        return res;
    }
};