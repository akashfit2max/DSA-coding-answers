class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // add in unordere set to mark them visited
        unordered_set<int>f(forbidden.begin(),forbidden.end());
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}}); // {co-ordinate,{jumps,prev_state}}
        f.insert(0);

        while(!q.empty()) {
            int c = q.front().first;
            int jumps = q.front().second.first;
            int prev_state = q.front().second.second;
            q.pop();

            // once reached dest
            if(c == x) return jumps;

            // it can go +a and -b
            int forward = c + a;
            int backward = c-b;

            // it can't go -ve , cnt go back twice
            if(backward > 0 && prev_state==0 && !f.count(backward)) {
                // jumped back change state to 1 so that it next time it wont jump back
                q.push({backward,{jumps+1,1}});
                f.insert(backward);
            }
            if(forward <= 10000 && !f.count(forward)) {
                q.push({forward,{jumps+1,0}});
                f.insert(forward);
            }
        }
        return -1;

    }
};