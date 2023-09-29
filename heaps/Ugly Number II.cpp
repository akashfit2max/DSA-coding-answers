class Solution {
public:
    int nthUglyNumber(int n) {
         priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        for(int i=0; i<n-1; i++) {
            long val = pq.top();
            pq.pop();
            while(!pq.empty() && pq.top() == val) pq.pop();
            pq.push(val*2);
            pq.push(val*3);
            pq.push(val*5);
        }

        return (int)pq.top();
    }
};












class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};