/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param schedule: a list schedule of employees
     * @return: Return a list of finite intervals 
     */
    static bool compare(Interval& a, Interval&b) {
        if(a.start == b.start) return a.end < b.end;
        else return a.start < b.start;
    }
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule) {
        vector<Interval>res;
        vector<Interval>intervals;
        for(int i=0; i<schedule.size(); i++) {
            for(int j=0; j<schedule[i].size()-1; j+=2) {
                intervals.push_back(Interval(schedule[i][j],schedule[i][j+1]));
            }
        }

        sort(intervals.begin(),intervals.end(),compare);

        for(auto& it : intervals) {
            cout<<it.start<<" "<<it.end;
            cout<<endl;
        }
        
        Interval temp = intervals[0];
        for(auto& it : intervals) {
            if(it.start > temp.end) {
                res.push_back(Interval(temp.end,it.start));
            }
            temp =  it.end > temp.end ? it : temp ;
        }
        return res;
    }
};