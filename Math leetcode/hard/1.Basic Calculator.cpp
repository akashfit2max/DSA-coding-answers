class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int sum = 0;
        stack<int>st;
        int n = s.length();

        for(int i=0; i<n; i++) {
            
            // if its a digit
            if(isdigit(s[i])) {
                int num = 0;
                // more than one digit
                while(s.length() > i && isdigit(s[i])) {
                    num =num*10 + (s[i]-'0');
                    i++;
                }
                sum += num*sign;
                i--;
            }

            else if(s[i] == '+') {
                sign = 1;
            }

            else if(s[i] == '-') {
                sign = -1;
            }
            // push into stack the sum and the sign
            else if(s[i] == '(') {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                sum = st.top()*sum;
                st.pop();
                sum += st.top();
                st.pop();
            }
        }
        return sum;
    }
};