class Solution {
public:
    int calculate(string s) {
        stack<int>stack;
        int num = 0;
        char sign = '+';
        int pre;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(isdigit(c)){
                num = num*10 + (c-'0');
            }
            if(c=='+'||c=='-'||c=='*'||c=='/'||i==s.size()-1){
                switch(sign){
                    case '+':
                        stack.push(num);
                        break;
                    case '-':
                        stack.push(-num);
                        break;
                    case '*':
                        pre = stack.top();
                        stack.pop();
                        stack.push(pre*num);
                        break;
                    case '/':
                        pre = stack.top();
                        stack.pop();
                        stack.push(pre/num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        int res = 0;
        while(!stack.empty()){
            res = res+stack.top();
            stack.pop();
        }
        return res;
    }
};