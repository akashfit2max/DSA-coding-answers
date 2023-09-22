class Solution {
public:
    unordered_set<string> op{"+","-","*","/"};
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto it : tokens) {
            if(op.find(it) == op.end()) s.push(stoi(it));
            else {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(it == "+") s.push(a+b);
                else if(it == "-") s.push(a-b);
                else if(it == "*") s.push(a*b);
                else s.push(a/b);
            }
        }
        return s.top();
    }
};