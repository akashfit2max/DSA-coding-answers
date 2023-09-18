class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>s;
        s.push(0);
        vector<int>ans(n,0);
        for(int i=1; i<temperatures.size(); i++) {
            // keep string the element in inc order. pop and store ans untill  the order is maintained
            while(!s.empty() && temperatures[i] > temperatures[s.top()]) {
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};