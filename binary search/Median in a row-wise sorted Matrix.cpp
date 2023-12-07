class Solution{   
public:
    int countSmallerThanMid(vector<int> &row, int mid)
    {
      auto it = upper_bound(row.begin(),row.end(),mid);
      return it-row.begin();
    }
    int median(vector<vector<int>> &A, int R, int C){
        // code here          
        int low = 1;
        int high = 1e9;
        int n = A.size();
        int m = A[0].size();
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
              cnt += countSmallerThanMid(A[i], mid);
            }
            if (cnt <= (n * m) / 2)
              low = mid + 1;
            else
              high = mid - 1;
          }
          return low;  
    }
};