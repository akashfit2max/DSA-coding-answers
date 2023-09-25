class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res(k);
        priority_queue<vector<int>>maxHeap;

        for(auto& p : points) {
            int x = p[0], y=p[1];
            int dist = x*x + y*y;
            maxHeap.push({dist,x,y});
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            res[i] = {top[1], top[2]};
        }
        
        return res;

    }
};