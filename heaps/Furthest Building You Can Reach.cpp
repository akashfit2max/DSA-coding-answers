class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n = h.size();
        int res = 0;
        int b = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        //we try to maintain top jumps in heap
        //just to keep a track of jumps
        //since we know; rope can give us more high
        //jumps while always good to avoid bricks
        //so we will maitain a min heap of jumps so far taken
        // when the taken jumps exceed the number of ladders that we have
        //we switch to bricks, and use them for jump and
        //when we run out of bricks, we stop
        for(int i=1; i<n; i++) {
            int diff = h[i]-h[i-1];
            if(diff <=0) {
                res = i;
                continue;
            }

            pq.push(diff);
            if(pq.size() > ladders) {
                b += pq.top();
                pq.pop();
                if( b > bricks) break;
            }
            res = i;
        }

        return res;
    }
};