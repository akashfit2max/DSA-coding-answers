class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        vector<int>ans;
        int rem = nums.size()-k;
        for(auto it : nums) {
            while(!st.empty() && st.top() > it && rem ) {
                st.pop();
                rem--;
            }
            st.push(it);
        }

        while(!st.empty() && rem--) {
            st.pop();
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};