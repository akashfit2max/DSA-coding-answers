int setBits(int N){
    // Write your code here.
    if((N & (N+1)) == 0) return N;
    return (N | (N+1));
}


// Sample Input 1:
// 10
// Sample Output 1:
// 11
// Explanation Of Sample Input 1:
// N=10
// The binary representation of 10 is 1010. After setting the rightmost unset bit it becomes 1011 which is 11.
// Sample Input 2:
// 7
// Sample Output 2:
// 7
// Explanation Of Sample Input 2:
// N=7
// The binary representation of 7 is 111. As there is no unset bit it remains the same.
// Constraints:
// 1 <= N <= 10^9
// Time Limit: 1 sec