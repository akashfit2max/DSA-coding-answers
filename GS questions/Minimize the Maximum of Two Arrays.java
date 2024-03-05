class Solution {
    private int gcd(int a, int b) {
        return b == 0? a : gcd(b, a % b);
    }

    public int minimizeSet(int d1, int d2, int u1, int u2) {
        long lo = 1, hi = (int) 10e10;
        long ans = hi;
        long lcm = ((long) d1 * (long) d2) / gcd(d1, d2);
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            int x = (int) (mid - mid / d1); // kitne number h jo d1 se divisibke nai h
            int y = (int) (mid - mid / d2); // kitne number h jo d2 se div nai h 
            int z = (int) (mid - mid / lcm); // jo bot d1 and d2 se divi h
            if (x < u1 || y < u2 || z < u1 + u2) {
                lo = mid + 1;
            } else {
                ans = Math.min(ans, mid);
                hi = mid - 1;
            }
        }

        return (int) ans;
    }
}

// TC: O(logn), SC: O(1)