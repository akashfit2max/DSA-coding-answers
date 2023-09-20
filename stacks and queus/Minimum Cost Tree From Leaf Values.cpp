class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int>s;
        s.push(INT_MAX);
        
        for(auto it : arr) {
            while(it > s.top()) {
                int mid = s.top();
                s.pop();
                res += mid * min(s.top(),it);
            }
            s.push(it);
        }

        while(s.size() > 2) {
            int num = s.top();
            s.pop();
            res += num * s.top();
        }
        return res;
    }
};