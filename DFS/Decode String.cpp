class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>st;
        string res = "";
        int ptr = 0;

        while(ptr < s.length()) {
            char ch = s[ptr];
            if(isdigit(ch)) {
                int num=0;
                while(ptr < s.length() && isdigit(s[ptr])) {
                    num = num*10 + s[ptr]-'0';
                    ptr++;
                }
                // push the number in nums stack
                nums.push(num);
            }
            else if(ch == '[') {
                // push the string made till now
                st.push(res);
                res = "";
                ptr++;
            }
            else if(ch == ']') {
                //append the already present string
                string temp = st.top();
                int count = nums.top();
                for(int i=1;i<=count;i++){
                    //append the string the times it has in the nums stack
                    temp+=res;
                }
                st.pop();
                nums.pop();
                res = temp;
                ptr++;
            }
            else {
                res += ch;
                ptr++;
            }
        }
        return res;
    }
};