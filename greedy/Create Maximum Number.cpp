class Solution {
public:
    vector<int> max_lex(vector<int>& nums, int k) {
        if(k>nums.size()) return {};
        vector<int>ans;
        stack<int>s;
        int rem = nums.size()-k;
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && nums[i] > s.top() && rem) {
                s.pop();
                rem--;
            }
            s.push(nums[i]);
        }

        while(rem--) {
            s.pop();
        }

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void merger(vector<int>&a, vector<int>&b, vector<int>& res) {
        int n = a.size() , m = b.size();
        int i=0, j=0;
        while(i<n && j<m) {
            if(a[i]==b[j]) {
                int ti = i, tj = j;
                // find until the num are not equal
                while(ti < n && tj < m && a[ti] == b[tj]) {
                    ti++;
                    tj++;
                }
                if(ti == n) res.push_back(b[j++]);
                else if(tj == m) res.push_back(a[i++]);
                else if(a[ti] > b[tj]) res.push_back(a[i++]);
                else res.push_back(b[j++]);
            }
            else if(a[i] > b[j]) {
                res.push_back(a[i]);
                i++;
            }
            else {
                res.push_back(b[j]);
                j++;
            }
        }
        while(i < n) res.push_back(a[i++]);
        while(j < m) res.push_back(b[j++]);

    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
         // We consider every possible case:
        // eg.1 Take maximum number of 0 digits from nums1 and maximum number of k digits from nums2 and merge them to  get a maximum number of k digits.
        // eg2. Take maximum number of 1 digits from nums1 and maximum number of k-1 digits from nums2 and merge them to get a maximum number of k digits.
        // eg3. Take maximum number of 2 digits from nums1 and maximum number of k-2 digits from nums2 and merge them to get a maximum number of k digits.
        // eg4. Take maximum number of 3 digits from nums1 and maximum number of k-3 digits from nums2 and merge them to get a maximum number of k digits.
        // and so on.................
        // Then take the maximum among all the above generated numbers as our answer.

        vector<int>ans;
        for(int i=0; i<=k; ++i) {
            vector<int> a = max_lex(nums1,i);
            vector<int> b = max_lex(nums2,k-i);
            vector<int>res;
            merger(a,b,res);
            if(res.size() == k) ans = max(ans,res);
        }
        return ans;
    }
};