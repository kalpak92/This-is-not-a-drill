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

    return 0;
}