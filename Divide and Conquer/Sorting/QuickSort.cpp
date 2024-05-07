#include <iostream>
#include <vector>

using namespace std;

class QuickSort {
public:
    void sort(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);

            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[end];
        int pivotIndex = start;

        for (int i = start; i < end; i++) {
            if (nums[i] <= pivot) {         // Sort in ascending order
                swap(nums, i, pivotIndex);      // swap(nums[i], nums[pivotIndex]
                pivotIndex++;
            }
        }

        swap(nums, end, pivotIndex);            // swap(nums[pivotIndex], nums[end])

        return pivotIndex;
    }

    void swap(vector<int>& nums, int& i, int& j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp; 
    }
};

void printVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> nums = { 5, 2, 4, 6, 1, 3 };
    QuickSort qs;
    cout << "Before sorting: ";
    printVector(nums);
    qs.sort(nums);
    cout << "After sorting: ";
    printVector(nums);

    return 0;
}