class Solution {
public:
    int countDigitOne(int n) {
        if(n==0) return 0;
        long base=1;
        int sum=0;
        
        while(base<=n)
        {
            int left = (int)(n/base/10);
            int curr = (int)(n/base%10);
            int right = (int)(n%base);
            if(curr > 1) 
            {
                sum+=(left+1)*base;
            }
            else if(curr==1)
            {
                sum+=left*base+(right+1);
            }
            else
            {
                sum+=left*base;
            }
            
            base*=10;
        }
        return sum;
    }
};