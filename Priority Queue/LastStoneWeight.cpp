/**
 * You are given an array of integers stones where stones[i] is the weight of the ith stone.
 * We are playing a game with the stones. 
 * On each turn, we choose the heaviest two stones and smash them together. 
 * Suppose the heaviest two stones have weights x and y with x <= y. 
 * 
 * The result of this smash is:
 *      - If x == y, both stones are destroyed, and
 *      - If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
 * At the end of the game, there is at most one stone left.
 * 
 * Return the weight of the last remaining stone. 
 * If there are no stones left, return 0.
 * 
 * Example 1:
 * Input: stones = [2,7,4,1,8,1]
 * Output: 1
 * 
 * Explanation: 
 * We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 * we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 * we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
 * 
 * Example 2:
 * Input: stones = [1]
 * Output: 1
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Create a maxHeap from the stones list
        priority_queue<int> maxHeap(begin(stones), end(stones));

        while (maxHeap.size() > 1) {
            // Get the two heaviest stones
            int x = maxHeap.top();
            maxHeap.pop();

            int y = maxHeap.top();
            maxHeap.pop();

            // If the stones are not equal, add the difference to the maxHeap
            if (x > y)
                maxHeap.push(x - y);
        }
        // Return the last stone weight
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

void printVector(vector<int>& v) {
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    Solution s;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << "Given stones: ";
    printVector(stones);
    cout << "The last stone weight is: " << s.lastStoneWeight(stones) << endl;
    return 0;
}