/**
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
 * return the k closest points to the origin (0, 0).
 * 
 * The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).
 * You may return the answer in any order. 
 * The answer is guaranteed to be unique (except for the order that it is in).
 * 
 * Example 1:
 * Input: points = [[1,3],[-2,2]], k = 1
 * Output: [[-2,2]]
 * 
 * Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
 * 
 * Example 2:
 * Input: points = [[3,3],[5,-1],[-2,4]], k = 2
 * Output: [[3,3],[-2,4]]
 * Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Approach: Using Partial Sort
     * Partial Sort takes the first k elements and sorts them in ascending order.
     * The rest of the elements are not sorted.
     * Rearranges elements such that the range [first, middle) contains the sorted middle − 
     *      first smallest elements in the range [first, last).
     * 
     * The order of equal elements is not guaranteed to be preserved. 
     * The order of the remaining elements in the range [middle, last) is unspecified.
     * 
     * template< class RandomIt, class Compare >
     * void partial_sort( RandomIt first, RandomIt middle, RandomIt last, Compare comp );
     *      Elements are sorted with respect to comp.
    */

    vector<vector<int>> kClosestUsingPartialSort(vector<vector<int>>& points, int k) {
        auto euclidDistanceCompare = [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        };
        partial_sort(points.begin(), points.begin() + k, points.end(), euclidDistanceCompare);

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    /**
     * Approach: Using nth_element
     * nth_element is a partial sorting algorithm that rearranges elements in [first, last) 
     * such that the element pointed at by nth is changed to whatever element would be in that position 
     * if [first, last) was sorted.
     * 
     * The order of the elements in the two partitions is unspecified.
     * 
     * template< class RandomIt, class Compare >
     * void nth_element( RandomIt first, RandomIt nth, RandomIt last, Compare comp );
     *      Elements are sorted with respect to comp.
    */
    vector<vector<int>> kClosestUsingNthElement(vector<vector<int>>& points, int k) {
        auto euclidDistanceCompare = [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        };
        nth_element(points.begin(), points.begin() + k - 1, points.end(), euclidDistanceCompare);

        // can return the output in any order
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    /**
     * Approach: Using Max Heap
     * We can use a max heap to store the k closest points to the origin.
     * We iterate through the points and push them into the max heap.
     * If the size of the max heap exceeds k, we pop the top element.
     * 
     * The comparator function is used to compare the euclidean distance of two points.
    */

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto euclidDistanceCompare = [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(euclidDistanceCompare)> maxHeap(euclidDistanceCompare);
        vector<vector<int>> result;

        for (const auto& point : points) {
            maxHeap.push(point);

            if (maxHeap.size() > k)
                maxHeap.pop();
        }
        
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return result;
    }
};

void printVector(const vector<vector<int>>& v) {
    for (const vector<int>& i : v)
        cout << "[" << i[0] << ", " << i[1] << "] ";
    cout << endl;
}

int main() {
    Solution s;
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    cout << "Given points: ";
    printVector(points);
    cout << "The k closest points to the origin are: ";
    printVector(s.kClosestUsingPartialSort(points, k));

    points = {{3, 3}, {5, -1}, {-2, 4}};
    k = 2;
    cout << "Given points: ";
    printVector(points);
    cout << "The k closest points to the origin are: ";
    printVector(s.kClosestUsingPartialSort(points, k));

    points = {{-2, 2}, {1, 3}};
    k = 1;
    cout << "Given points: ";
    printVector(points);
    cout << "The k closest points to the origin are: ";
    printVector(s.kClosestUsingNthElement(points, k));

    return 0;
}