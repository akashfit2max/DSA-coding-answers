class Solution {
public:
    int lowerBound(vector<int>arr, int n, int x) {
        int l = 0, h=n-1;
        int ans = n;
        while(l<=h) {
            int m = l + (h-l)/2;
            if(arr[m] >= x) {
                ans = m;
                h = m-1;
            }
            else {
                l = m+1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>arr, int n, int x) {
        int l = 0, h=n-1;
        int ans = n;
        while(l<=h) {
            int m = l + (h-l)/2;
            if(arr[m] > x) {
                ans = m;
                h = m-1;
            }
            else {
                l = m+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,n,target);
        int ub = upperBound(nums,n,target);
        // if the number doesn't exist or the lb is out of range
        // [5,7,7,8,8,10] t = 6
        // lb = [1] = 7 != 6
        // [5,7,7,8,8,10] t = 11
        // lb = 6 11 doesn't exist
        if(lb == n || nums[lb] != target) {
            return {-1,-1};
        }
        return {lb,ub-1};
    }
};