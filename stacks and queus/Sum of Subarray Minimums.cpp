class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>next_smaller(n),prev_smaller(n);
        stack<int>ns;
        stack<int>ps;

        // if there is no smaller element in the left or right of the array
        for(int i=0; i<n; i++) {
            next_smaller[i] = n-i-1;
            prev_smaller[i] = i;
        }

        // finding next smaller
        for(int i=0; i<n; i++) {
            while(!ns.empty() && arr[ns.top()] > arr[i]) {
                next_smaller[ns.top()] = i-ns.top()-1;
                ns.pop();
            }
            ns.push(i);
        }

        // prev smaller
        for(int i=n-1; i>=0; i--) {
            while(!ps.empty() && arr[ps.top()] >= arr[i]) {
                prev_smaller[ps.top()] = ps.top()-i-1;
                ps.pop();
            }
            ps.push(i);
        }

        long long ans = 0;
        int mod = 1e9+7;
    
        for(int i=0; i<n; i++) {
            ans=(ans+(arr[i]*(long long)(next_smaller[i]+1)*(prev_smaller[i]+1))%mod)%mod;
        }
        return int(ans);
    }
};