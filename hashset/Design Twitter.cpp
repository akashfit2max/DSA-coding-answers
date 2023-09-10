class Twitter {
public:
    map<int,set<int>>friends; // user can have many followers
    priority_queue<vector<int>>timeline; // to store the tweets in priority order
    int curr = 0; // keep track of current time
    Twitter() {
        friends.clear();
        curr = 0;
        timeline = priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push({curr++,userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>>userTimeline = timeline;
        int n = 0;
        while(!userTimeline.empty() && n < 10) {
            auto topTweet = userTimeline.top();
            userTimeline.pop();
            // checking if the userid in of the user or of his friends
            if(topTweet[1] == userId || friends[userId].count(topTweet[1])) {
                ans.push_back(topTweet[2]);
                n++;
            }
        } 
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */


 