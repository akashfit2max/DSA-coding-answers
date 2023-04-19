class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = neededTime[0];
        int maxtime = neededTime[0];
        int ans = 0;
        int i = 1;
        while(i < colors.length()) {
            if(colors[i] == colors[i-1]) {
                sum += neededTime[i];
                maxtime = max (maxtime , neededTime[i]);
                i++;
            }
            else {
                ans += sum - maxtime;
                sum = neededTime[i];
                maxtime = neededTime[i];
                i++;
            }

        }
        ans += sum-maxtime;
        return ans; 
    }
};


Maintain the running sum and max value for repeated letters.