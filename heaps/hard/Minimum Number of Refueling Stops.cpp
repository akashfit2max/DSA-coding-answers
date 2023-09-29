class Solution {
public:
    int minRefuelStops(int t, int sf, vector<vector<int>>& s) {
        int i=0, res;
        priority_queue<int>pq;

        for(res = 0; sf < t; res++) {
            // add all fuels station jo bhee curr dist k under aajae
            while(i < s.size() && s[i][0] <= sf) {
                pq.push(s[i][1]);
                i++;
            }

            if(pq.empty()) return -1;
            
            // max fuel add kro for optimal sol
            sf += pq.top();
            pq.pop();
        }
        return res;

    }
};