/**
 * You are given an integer n. There are n rooms numbered from 0 to n - 1.
 * You are given a 2D integer array meetings where meetings[i] = [starti, endi] means 
 * that a meeting will be held during the half-closed time interval [starti, endi). 
 * All the values of starti are unique.
 * 
 * Meetings are allocated to rooms in the following manner:
 * Each meeting will take place in the unused room with the lowest number.
 * If there are no available rooms, the meeting will be delayed until a room becomes free. 
 *      The delayed meeting should have the same duration as the original meeting.
 * When a room becomes unused, meetings that have an earlier original start time should be given the room.
 * 
 * Return the number of the room that held the most meetings. 
 * If there are multiple rooms, return the room with the lowest number.
 * 
 * A half-closed interval [a, b) is the interval between a and b including a and not including b.
 * 
 * Example 1:
 * Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
 * Output: 0
 * Explanation:
 *      - At time 0, both rooms are not being used. The first meeting starts in room 0.
 *      - At time 1, only room 1 is not being used. The second meeting starts in room 1.
 *      - At time 2, both rooms are being used. The third meeting is delayed.
 *      - At time 3, both rooms are being used. The fourth meeting is delayed.
 *      - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
 *      - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
 * Both rooms 0 and 1 held 2 meetings, so we return 0. 
 * 
 * Example 2:
 * Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
 * Output: 1
 * Explanation:
 *      - At time 1, all three rooms are not being used. The first meeting starts in room 0.
 *      - At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
 *      - At time 3, only room 2 is not being used. The third meeting starts in room 2.
 *      - At time 4, all three rooms are being used. The fourth meeting is delayed.
 *      - At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
 *      - At time 6, all three rooms are being used. The fifth meeting is delayed.
 *      - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
 * 
 * Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 * 
 * Constraints:
 * 1 <= n <= 100
 * 1 <= meetings.length <= 10^5
 * meetings[i].length == 2
 * 0 <= starti < endi <= 5 * 10^5
 * 
 * All the values of starti are unique.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort the meetings based on their start time
        auto compare_meeting_start_time = [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        };
        sort(meetings.begin(), meetings.end(), compare_meeting_start_time);

        // Create a maxHeap for engaged rooms
        // maxHeap stores {current_meeting_end_time, room_number}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged_rooms;

        // Create a minHeap for unused_rooms
        // Each node stores the {room_number}
        priority_queue<int, vector<int>, greater<int>> unused_rooms;

        // map to store the frequency of meetings in each room_number
        unordered_map<int, int> meetings_per_room;

        // Initialize all meeting_room to be unused
        for (int i = 0; i < n; i++)
            unused_rooms.push(i);

        for (auto meeting : meetings) {
            int start_time = meeting[0];
            int end_time = meeting[1];

            // Move engaged meeting room with end_time <= current meeting start_time to the unused pool
            while (engaged_rooms.size() > 0 && engaged_rooms.top().first <= start_time) {
                int room_number = engaged_rooms.top().second;
                engaged_rooms.pop();

                unused_rooms.push(room_number);
            }

            // if there are multiple empty rooms, choose the one with the lower room_number
            if (unused_rooms.size() > 0) {
                int room_number = unused_rooms.top();
                unused_rooms.pop();

                meetings_per_room[abs(room_number)]++;
                engaged_rooms.push(make_pair(end_time, room_number));   // mark the room as engaged
            } else {
                // no more empty rooms
                // wait for the engaged room with the nearest ending time to empty out

                pair<long long, int> topmost = engaged_rooms.top();
                engaged_rooms.pop();

                meetings_per_room[topmost.second]++;

                // duration has to be start_time
                long long new_end_time = topmost.first; // current meeting end time
                new_end_time += (end_time - start_time);    // add the meeting time

                // mark the room as engaged since we will use it for the meeting
                engaged_rooms.push(make_pair(new_end_time, topmost.second));
            }
        }

        // Find the meeting room with the highest usage
        // Break tie by selecting the lower meeting room number
        int meeting_room_with_max_frequency = 0;
        for (int i = 0; i < n; i++) {
            if (meetings_per_room[i] > meetings_per_room[meeting_room_with_max_frequency])
                meeting_room_with_max_frequency = i;
        }
        return meeting_room_with_max_frequency;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    int n = 2;
    cout << "Most booked room: " << sol.mostBooked(n, meetings) << endl;

    meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    n = 3;
    cout << "Most booked room: " << sol.mostBooked(n, meetings) << endl;

    return 0;
}