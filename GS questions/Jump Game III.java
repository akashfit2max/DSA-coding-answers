class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);

        while (!queue.isEmpty()) {
            int curr = queue.poll();

            if (arr[curr] == 0) return true;

            if (arr[curr] < 0) continue; // already visited

            if (curr + arr[curr] < n) queue.offer(curr + arr[curr]);
            if (curr - arr[curr] >= 0) queue.offer(curr - arr[curr]);

            // mark vis
            arr[curr] = -arr[curr];
        }
        return false;
    }
}