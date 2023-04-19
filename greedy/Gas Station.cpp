class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost = 0, total_gas = 0;
        for(auto it : gas) {
            total_gas += it;
        }
        for(auto it : cost) {
            total_cost += it;
        }
        if(total_gas < total_cost) {
            return -1;
        }
        int start = 0, current_gas = 0;
        for(int i=0; i<gas.size(); i++) {
            current_gas += gas[i]-cost[i];
            if(current_gas < 0) {
                start = i+1;
                current_gas = 0;
            }
        }
        return start;
    }
};