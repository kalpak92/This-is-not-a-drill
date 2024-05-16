/**
 * Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
 * return the minimum number of conference rooms required.
 * 
 * Example 1:
 * Input: intervals = [[0,30],[5,10],[15,20]]
 * Output: 2
 * 
 * Example 2:
 * Input: intervals = [[7,10],[2,4]]
 * Output: 1
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;
        
        // Sort the array based on the starting time of the meeting
        auto compStartingTime = [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), compStartingTime);

        // Create a minHeap to get the meeting that finishes first
        // Check if the intervals overlap, then we need a separate room, else merge them
        auto compEndTime = [](vector<int> a, vector<int> b) {
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compEndTime)> minHeap(compEndTime);

        minHeap.push(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (minHeap.top()[1] <= intervals[i][0]) {
                // endTime <= startTime of the next meeting
                // reuse the same room
                // merge it 
                vector<int> temp = minHeap.top();
                minHeap.pop();
                temp[1] = intervals[i][1];
                minHeap.push(temp);
            } else {
                // need new room
                minHeap.push(intervals[i]);
            }
        }
        return minHeap.size();
    }
};

void printVector(vector<vector<int>> intervals) {
    cout << "Given intervals :" << endl;
    for (auto interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
    printVector(intervals);
    cout << "The minimum number of meeting rooms needed: " << sol.minMeetingRooms(intervals) << endl;

    intervals = {{7,10},{2,4}};
    printVector(intervals);
    cout << "The minimum number of meeting rooms needed: " << sol.minMeetingRooms(intervals) << endl;

    return 0;
}