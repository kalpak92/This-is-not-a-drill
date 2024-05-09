#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSortArray(nums, 0, nums.size() - 1);
        return nums;
    }

private: 
      void mergeSortArray(vector<int>& nums, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = (left + right) / 2;

            // Sort first and second halves
            mergeSortArray(nums, left, mid);
            mergeSortArray(nums, mid + 1, right);

            // Merge the sorted halves
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& arr, int left, int mid, int right)  {
        // Find sizes of two sub-arrays to be merged
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temp arrays
        vector<int> L(n1);
        vector<int> R(n2);

        // Copy data to temp arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (int j = 0; j < n2; ++j)
            R[j] = arr[mid + 1 + j];

        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarray array
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) { // tie - breaker : focus on the left array
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[] if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[] if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

void printVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}

int main() {

    vector<int> nums{ 12, 11, 13, 5, 6, 7 };
    
    cout << "Given array is \n";
    printVector(nums);

    MergeSort().sortArray(nums);

    cout << "\nSorted array is \n";
    printVector(nums);
    return 0;

}