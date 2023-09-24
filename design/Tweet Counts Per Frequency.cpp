class TweetCounts {
public:
    unordered_map<string,vector<int>>mp;
    TweetCounts() {
        mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string minute, int st, int et) {
        if(freq == "minute") {
            vector<int>ans((et-st)/60+1,0);
            for(auto it : mp[minute]) {
                if(it >= st && it <= et) {
                    ans[(it-st)/60]++;
                }
            }
            return ans;
        }

        else if(freq == "hour") {
            vector<int>ans((et-st)/3600+1,0);
            for(auto it : mp[minute]) {
                if(it >= st && it <= et) {
                    ans[(it-st)/3600]++;
                }
            }
            return ans;
        }

        else {
            vector<int>ans((et-st)/(24*3600)+1,0);
            for(auto it : mp[minute]) {
                if(it >= st && it <= et) {
                    ans[(it-st)/(24*3600)]++;
                }
            }
            return ans;
        }
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */