/**
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, 
 * and is able to see the 10 most recent tweets in the user's news feed.
 * 
 * Implement the Twitter class:
 *      Twitter() Initializes your twitter object.
 *      void postTweet(int userId, int tweetId) 
 *          Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
 *      List<Integer> getNewsFeed(int userId) 
 *          Retrieves the 10 most recent tweet IDs in the user's news feed. 
 *          Each item in the news feed must be posted by users who the user followed or by the user themself. 
 *          Tweets must be ordered from most recent to least recent.
 *      void follow(int followerId, int followeeId) 
 *          The user with ID followerId started following the user with ID followeeId.
 *      void unfollow(int followerId, int followeeId) 
 *          The user with ID followerId started unfollowing the user with ID followeeId.
 * 
 * Example 1:
 * Input
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * Output
 * [null, null, [5], null, null, [6, 5], null, [5]]
 * 
 * Explanation
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
 * twitter.follow(1, 2);    // User 1 follows user 2.
 * twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
 * twitter.unfollow(1, 2);  // User 1 unfollows user 2.
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Twitter {
public:
    Twitter() {
        this->timeStamp = 0;
        this->feedMaxNum = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        // Add the tweet to the user's list of tweets
        tweets[userId].push_back(make_pair(timeStamp, tweetId));
        timeStamp++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed.
     * Each item in the news feed must be posted by users who the user followed or by the user herself.
     * Tweets must be ordered from most recent to least recent.
     * */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        // Add the tweets of the user to the max heap
        for (auto itr = tweets[userId].begin(); itr != tweets[userId].end(); itr++) {
            maxHeap.push(*itr);
        }

        // Push all the tweets of all the users that the given userId follows
        for (auto itr = followers[userId].begin(); itr != followers[userId].end(); itr++) {
            int user = *itr;
            for (auto itr1 = tweets[user].begin(); itr1 != tweets[user].end(); itr1++)
                maxHeap.push(*itr1);
        }

        // Get the 10 most recent tweets
        vector<int> result;
        while (maxHeap.size() > 0) {
            result.push_back(maxHeap.top().second);

            if (result.size() == 10)
                break;
            maxHeap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        // Add the followee to the follower's list
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Remove the followee from the follower's list
        followers[followerId].erase(followeeId);
    }

private:
    int timeStamp;
    int feedMaxNum;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
};


int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    vector<int> result = twitter.getNewsFeed(1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    result = twitter.getNewsFeed(1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    twitter.unfollow(1, 2);
    result = twitter.getNewsFeed(1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}