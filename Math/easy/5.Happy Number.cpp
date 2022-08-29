class Solution {
public:
    
    int getNext(int n)
    {
        int temp = 0;
        
        while(n>0)
        {
            int d = n%10;
            n = n/10;
            temp+= d*d;
        }
        return temp;
    }
    
    bool isHappy(int n) {
        
        while(n!=1 && n!=4)
        {
            n = getNext(n);
        }
        
        return n==1;
    }
};