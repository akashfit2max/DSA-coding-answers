class Solution {
public:
    bool isPalindrome(int x) {
         if(x<0) {
            return false;
        }
        long temp = x;
        long ans=0;
        while(temp!=0) {
            ans = ans*10 + temp%10;
            temp /= 10;
        }
        if(x==ans) {
            return true;
        }
        else {
            return false;
        }
    }
};