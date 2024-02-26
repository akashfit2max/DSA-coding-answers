import java.util.ArrayList;
public class Solution
{
    public static int maximumOnesRow(ArrayList<ArrayList<Integer>> matrix, int n, int m)
    {
        int maxCount = Integer.MIN_VALUE;
        int countOne = 0;
        int rowIndex = -1;

        for(int i=0; i<n; i++) {
            countOne = m - lowerBound(matrix.get(i), m, 1);
            if(countOne > maxCount) {
                maxCount = countOne;
                rowIndex = i;
            }
        }
        return rowIndex;
    }

    public static int lowerBound(ArrayList<Integer> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr.get(mid) >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }
}