class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonic queue
        deque<int>dq;
        vector<int>ans;

        for(int s = 0; s < nums.size(); s++) {
            // remove the front element once reach the window size
            if(dq.front() == s-k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[s]) {
                dq.pop_back();
            }

            dq.push_back(s);

            if(s-k+1 >=0 ) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};