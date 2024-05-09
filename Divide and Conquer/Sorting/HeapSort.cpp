/**
 * Heap Sort
*/

#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSortArray(nums);
        return nums;
    }

private:
    void heapSortArray(vector<int>& nums) {
        int n = nums.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(nums, n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(nums[0], nums[i]);

            // call max heapify on the reduced heap
            heapify(nums, i, 0);
        }
    }

    // To heapify a subtree rooted with node i which is an index in nums[]
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (l < n && nums[l] > nums[largest])
            largest = l;

        // If right child is larger than largest so far
        if (r < n && nums[r] > nums[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(nums[i], nums[largest]);

            // Recursively heapify the affected sub-tree
            heapify(nums, n, largest);
        }
    }
};

void printVector(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> nums{5, 2, 4, 6, 1, 3 };

    HeapSort hs;
    hs.sortArray(nums);
    printVector(nums);

    return 0;
}