class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;

        for (auto &tweet : tweets) {
            if (tweet.first == userId || following[userId].count(tweet.first)) {
                feed.push_back(tweet.second);
            }

            if (isFull(feed)) {
                break;
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
    using Tweet = list<pair<int, int>>; // {userId, tweetId}
    Tweet tweets;
    const int maxFeeds = 10;
    unordered_map<int, unordered_set<int>> following;

    inline bool isFull(const vector<int>& feed) {return feed.size() >= maxFeeds;}
};