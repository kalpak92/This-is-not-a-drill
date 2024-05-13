/**
 * You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. 
 * Each cycle or interval allows the completion of one task. 
 * Tasks can be completed in any order, but there's a constraint: 
 *      identical tasks must be separated by at least n intervals due to cooling time.
 * 
 * ​Return the minimum number of intervals required to complete all tasks.
 * 
 * Example 1:
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
 * After completing task A, you must wait two cycles before doing A again. 
 * The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. 
 * By the 4th cycle, you can do A again as 2 intervals have passed.
 * 
 * Example 2:
 * Input: tasks = ["A","C","A","B","D","B"], n = 1
 * Output: 6
 * Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
 * With a cooling interval of 1, you can repeat a task after just one other task.
 * 
 * Example 3:
 * Input: tasks = ["A","A","A", "B","B","B"], n = 3
 * Output: 10
 * Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
 * There are only two types of tasks, A and B, which need to be separated by 3 intervals. 
 * This leads to idling twice between repetitions of these tasks.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;

        auto taskFrequencyCompare = [&taskCount](char task1, char task2) {
            return taskCount[task1] < taskCount[task2];
        };
        priority_queue<char, vector<char>, decltype(taskFrequencyCompare)> maxHeap(taskFrequencyCompare);
        
        int result = 0;

        // Build the map having the occurrences of each task
        for (const char& task : tasks) {
            taskCount[task]++;
        }

        for (const auto& elem : taskCount) {
            maxHeap.push(elem.first);
        }

        while (!maxHeap.empty()) {
            // n is the cooling period between two occurrences of the same task.
            // However, in each cycle, we also need to schedule one taks
            int interval = n + 1;
            queue<char> waitQueue;

            // Fill the interval with tasks until we run out of tasks or the interval becomes 0.
            while (interval > 0 && !maxHeap.empty()) {
                char task = maxHeap.top();
                maxHeap.pop();
                taskCount[task]--;

                // Add the task to the waitQueue to process it later in case of repeating occurrences.
                waitQueue.push(task);

                interval--;
                result++;
            }

            // Add the tasks from the waitQueue back to the maxHeap if they have more occurrences.
            while (!waitQueue.empty()) {
                char task = waitQueue.front();
                waitQueue.pop();

                if (taskCount[task] > 0)
                    maxHeap.push(task);
            }

            // If the maxHeap is empty, we have processed all the tasks.
            if (maxHeap.empty())
                break;
            
            // If the interval is still greater than 0, we need to add idle cycles.
            result = result + interval;
        }
        return result;
    }

    /**
     * This is based on a greedy algorithm. 
     * The greedy choice is to always schedule the task with the highest frequency that meets the cooling period constraint.
     * 
     * We first count the number of occurrences of each task and store them in taskCount.
     * We sort taskCount in ascending order so that the task with the maximum frequency is at the end.
     * We calculate the maximum number of idle slots we might have.
     * We iterate over the rest of the tasks and fill the idle slots.
     * If there are still idle slots left, 
     *      we add the number of tasks to the number of idle slots and return the result. 
     * Otherwise, we return the number of tasks.
     * 
     * This greedy approach ensures that the tasks are scheduled in a way that minimizes the total number of intervals.
    */

    int leastIntervalOptimized(vector<char>& tasks, int n) {
        vector<int> taskCount(26, 0);
        for (char task : tasks) {
            taskCount[task - 'A']++;
        }
        
        sort(taskCount.begin(), taskCount.end());   // 
        
        // get the maximum frequency of any task
        // We subtract one from the maximum frequency to calculate the number of idle slots 
        // that we would have after scheduling the most frequent task.
        // The reason we subtract one is that we don't need to wait for any idle slots 
        // after the last occurrence of the most frequent task.
        // For 3'A', we need at least 2 idle slots to separate them.
        // 'A' -> idle -> idle -> 'A' -> idle -> idle -> 'A'
        int maxVal = taskCount[25] - 1;

        // maxVal is the max number of idle slots we would have after scheduling each occurrence of the most frequent task, except the last one.
        // n is the cooling period between two occurrences of the same task.
        // We then multiply maxVal by n to calculate the maximum number of idle slots that we might have; except the last one.
        // This is based on the assumption that 
        // we can schedule the most frequent task first and 
        // then schedule n idle slots before we can schedule the same task again.
        int idleSlots = maxVal * n;
        
        // Iterate from the 2nd most frequent task to the least frequent task
        for (int i = 24; i >= 0 && taskCount[i] > 0; i--) {
            // Try to fill the idle slots with the current task
            // The number of idle slots that we can fill with the current task is
            // the minimum of the frequency of the current task and 
            // the maximum number of slots that can be filled without scheduling the same task consecutively (maxVal).
            // The min function is used to ensure that we don't subtract more than the number of idle slots that we have.
            idleSlots -= min(taskCount[i], maxVal);
        }
        
        // If there are still idle slots left, we add the number of idle slots to the number of tasks.
        // This is because we need to wait for the idle slots to be filled befor we can finish all the tasks.
        // So the total number of intervals is the number of tasks plus the number of idle slots.
        // Else, if there are no idle slots left, we return the number of tasks.
        // This is because we can finish all the tasks without waiting for any idle slots.
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};

/**
 * The time complexity of the optimized approach for the task scheduling problem is O(N), 
 * where N is the number of tasks.
 * 
 * Here's why:
 * Counting the number of occurrences of each task takes O(N) time, where N is the number of tasks.
 * Sorting the task count array takes O(26 log 26) time, which is essentially O(1) because the size of the array is fixed (26 letters in the English alphabet).
 * The for loop that fills the idle slots runs 26 times in the worst case (when all tasks are different), 
 * so it takes O(1) time.
 * 
 * Therefore, the overall time complexity is O(N) + O(1) + O(1) = O(N).
 * However, if the input tasks are not limited to 26 types and can be considered as M types, 
 * the time complexity of sorting would be O(M log M), and the time complexity of the for loop would be O(M). So, the overall time complexity would be O(N + M log M).
*/

int main() {
    Solution solution;
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    vector<char> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    int n2 = 1;
    int n3 = 3;

    cout << "Least intervals to complete all tasks: " << solution.leastInterval(tasks1, n1) << endl;
    cout << "Least intervals to complete all tasks: " << solution.leastInterval(tasks2, n2) << endl;
    cout << "Least intervals to complete all tasks: " << solution.leastInterval(tasks3, n3) << endl;

    cout << "Least intervals to complete all tasks: " << solution.leastIntervalOptimized(tasks1, n1) << endl;
    cout << "Least intervals to complete all tasks: " << solution.leastIntervalOptimized(tasks2, n2) << endl;
    cout << "Least intervals to complete all tasks: " << solution.leastIntervalOptimized(tasks3, n3) << endl;

    return 0;
}