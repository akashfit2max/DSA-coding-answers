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


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.size(), i=0, j=0;
        while(j<n){
            int curCost = 0, maxTime = 0;
            while(j<n && colors[i]==colors[j]){
                curCost += neededTime[j];
                maxTime = max(maxTime, neededTime[j]);
                ++j;
            }
            cost += curCost - maxTime;
            i=j;
        }
        return cost;
    }
};