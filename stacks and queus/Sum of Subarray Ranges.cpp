
class Solution {
public:
    void print(vector<int>arr) {
        for(auto it : arr) {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    long long subArrayRanges(vector<int>& nums) {
        stack<int>inc,dec;
        int n = nums.size();

        vector<int>ls(n),rs(n),ll(n),rl(n);

        // initialize
        for(int i=0; i<n; i++) {
            ls[i] = ll[i] = i+1;
            rs[i] = rl[i] = n-i;
        }

        // finding left less and right less
        for(int i=0; i<n; i++) {
            while(!inc.empty() && nums[inc.top()] > nums[i]) {
                rs[inc.top()] = i - inc.top();
                inc.pop();
            }
            ls[i] = inc.empty() ? i+1 : i-inc.top();
            inc.push(i);
        }

        // finding left large and right large
        for(int i=0; i<n; i++) {
            while(!dec.empty() && nums[dec.top()] < nums[i]) {
                rl[dec.top()] = i - dec.top();
                dec.pop();
            }
            ll[i] = dec.empty() ? i+1 : i-dec.top();
            dec.push(i);
        }

        print(ls);
        print(rs);
         print(ll);
        print(rl);
        long long sum = 0;
        for(int i=0; i<n; i++) {
            long long curr_diff = ll[i]*rl[i] - ls[i]*rs[i];
            sum += nums[i]*curr_diff;
        }

        return sum;
    }
};