#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>& v) {
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

void printVector(vector<pair<int, int>>& v) {
    for (pair<int, int>& i : v)
        cout << "{" << i.first << ", " << i.second << "} ";
    cout << endl;
}

int main() {
    /**
     * std::sort sorts the elements in the range in ascending order. 
     * The order of equal elements is not guaranteed to be preserved, 
     * which means std::sort is not a stable sort.
    */
    vector<int> v = {4, 2, 2, 8, 3, 3, 1};
    cout << "Before sorting: " << endl;
    printVector(v);
    sort(v.begin(), v.end());
    // v: {1, 2, 2, 3, 3, 4, 8}
    printVector(v);


    /**
     * std::stable_sort also sorts the elements in the range in ascending order, 
     * but it is a stable sort, which means that the relative order of equal elements is preserved.
    */
    vector<pair<int, int>> listPair = {{1, 2}, {3, 4}, {3, 5}, {2, 6}, {2, 7}};
    cout << "Before sorting: " << endl;
    printVector(listPair);
    stable_sort(listPair.begin(), listPair.end());
    // v: {{1, 2}, {2, 6}, {2, 7}, {3, 4}, {3, 5}}
    /**
     * In this example, the pairs {2, 6} and {2, 7} and the pairs {3, 4} and {3, 5} are equal in terms of the first element, 
     * and std::stable_sort preserves their relative order.
     * The trade-off is that std::stable_sort may be slower and use more memory than std::sort, 
     * especially for large ranges. 
     * So you should use std::stable_sort only when you need to preserve the relative order of equal elements.
    */
    printVector(listPair);

    return 0;
}