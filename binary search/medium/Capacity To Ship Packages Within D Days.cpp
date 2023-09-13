class Solution {
public:
    int findDays(vector<int>& weights, int cap) {
        int day = 1, load = 0;
        for(int i=0; i<weights.size(); i++) {
            // 1,2,3,4,5
            // cap = 15
            if(weights[i] + load > cap) {
                day += 1;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return day; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(),weights.end(),0);

        while( l<= h) {
            int m  = l + (h-l)/2;
            // m = capacity
            // get the min num of days
            int numOfDays = findDays(weights,m);
            if(numOfDays <= days) {
                h = m-1;
            }
            else {
                l = m+1;
            }
        }
        return l;
    }
};