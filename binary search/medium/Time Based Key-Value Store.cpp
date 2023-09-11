class TimeMap {
public:
    unordered_map<string,vector<pair<string, int>>> mTime;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mTime[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int res = -1;
        if(mTime.find(key) != mTime.end()) {
            int s = 0, e = mTime[key].size()-1;
            while(s <= e) {
                int m = s + (e-s)/2;
                if(mTime[key][m].second == timestamp) {
                    return mTime[key][m].first;
                }
                else if (mTime[key][m].second < timestamp) {
                    res = m;
                    s = m+1;
                }
                else {
                    e = m-1;
                }
            }
        }
        return (res != -1) ? mTime[key][res].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */




