class Twitter {
public:
    int timeStamp = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap;

        for(auto &t : tweets[userId]) maxHeap.push(t);
        for(int f : following[userId]) {
            for(auto &t : tweets[f]) maxHeap.push(t);
        }

        vector<int> ans;
        int count = 0;
        while(!maxHeap.empty() && count < 10) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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