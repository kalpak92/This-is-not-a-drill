/**
 * Suppose LeetCode will start its IPO soon. 
 * In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. 
 * Since it has limited resources, it can only finish at most k distinct projects before the IPO. 
 * Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
 * 
 * You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
 * Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
 * Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
 * The answer is guaranteed to fit in a 32-bit signed integer.
 * 
 * Example 1:
 * Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
 * Output: 4
 * Explanation: Since your initial capital is 0, you can only start the project indexed 0.
 * After finishing it you will obtain profit 1 and your capital becomes 1.
 * With capital 1, you can either start the project indexed 1 or the project indexed 2.
 * Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
 * Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
 * 
 * Example 2:
 * Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
 * Output: 6
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto compCapital = [](pair<int, int> left, pair<int, int> right) {
            return left.first > right.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compCapital)> capitalPerProjectMinHeap(compCapital);

        auto compProfits = [](pair<int, int> left, pair<int, int> right) {
            return left.second < right.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compProfits)> profitsPerProjectMaxHeap(compProfits);


        // Construct a minHeap of {capital, profit}
        for (int i = 0; i < capital.size(); i++) {
            capitalPerProjectMinHeap.push(make_pair(capital[i], profits[i]));
        }

        // Work on k projects
        for (int i = 0; i < k; i++) {
            // Extract all projects feasible within the current capital
            // Sort them in decreasing order of profits
            while (!capitalPerProjectMinHeap.empty() && capitalPerProjectMinHeap.top().first <= w) {
                profitsPerProjectMaxHeap.push(capitalPerProjectMinHeap.top());
                capitalPerProjectMinHeap.pop();
            }

            if (profitsPerProjectMaxHeap.empty())   // break preemptively if there's no project
                break;
            
            w += profitsPerProjectMaxHeap.top().second; // choose the project with the maxProft
            profitsPerProjectMaxHeap.pop();             // Remove the project to using it repetitively
        }
        return w;
    }
};

/**
 * The time complexity of this algorithm is O(N log N + K log N).
 * 
 * Here's why:
 * Constructing the capitalPerProjectMinHeap takes O(N log N) time, where N is the number of projects. 
 * This is because each insertion into a heap takes O(log N) time, and we do this N times.
 * 
 * The outer loop runs K times, where K is the number of projects we can pick. 
 * Inside this loop, we potentially insert all projects into profitsPerProjectMaxHeap, and each insertion takes O(log N) time. 
 * Therefore, the time complexity of this part is O(K log N).
 * 
 * However, in the worst-case scenario, K could be equal to N. 
 * So, the time complexity of the second part could also be considered as O(N log N).
 * Therefore, the overall time complexity is O(N log N + K log N), or O(N log N) in the worst-case scenario.
*/

int main() {
    Solution s;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    int k = 2, w = 0;
    cout << s.findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}