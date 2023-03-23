class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxProfit = INT_MIN;
        for(int i=0; i<prices.size(); i++) {
            minprice = min(minprice,prices[i]);
            maxProfit = max(maxProfit, prices[i]-minprice);
        }

        return maxProfit;
    }
};