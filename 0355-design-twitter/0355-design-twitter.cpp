class Twitter {
public:
    
    unordered_map<int, set<int>>mpp;
    int time=0;
    priority_queue<vector<int>>pq;
    
    Twitter() {
        mpp.clear();
        time=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({time++,tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>>temp=pq;
        int n=0;
        while(!temp.empty() && n<10){
            auto top=temp.top();
            temp.pop();
            if(top[2]==userId || mpp[userId].count(top[2])>0){
                ans.push_back(top[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mpp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mpp[followerId].erase(followeeId);
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