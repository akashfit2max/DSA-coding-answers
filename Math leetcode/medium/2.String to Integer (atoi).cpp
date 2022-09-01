class Solution {
public:
    int myAtoi(string s) {
        int n = 0 , l = s.length();
        bool flag = false;
        int index = 0;
        for(;s[index]==' ';index++);
        if(s[index] == '-') {flag = true;index++;}
        else if(s[index] == '+') {flag = false;index++;}
        while(s[index] >= '0' && s[index] <= '9' && index < l){
            if(n > INT_MAX/10 )
                return flag ? INT_MIN : INT_MAX;
            n = n * 10;
            if(n > INT_MAX - (s[index] - '0'))
                return flag ? INT_MIN : INT_MAX;
            n += s[index] - '0';
            index++;
        }
        
        return flag ? -1*n : n;
    }
};