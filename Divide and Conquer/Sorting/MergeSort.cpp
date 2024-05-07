#include <iostream>
#include <array>
using namespace std;

class MergeSort {
public:
    void sort(array<int, 6>& arr, int left, int right) {
        if (left < right) {
            // Find the middle point
            int mid = (left + right) / 2;

            // Sort first and second halves
            sort(arr, left, mid);
            sort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

private:
    void merge(array<int, 6>& arr, int left, int mid, int right)  {
        // Find sizes of two sub-arrays to be merged
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temp arrays
        array<int, 100> L;
        array<int, 100> R;

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

void printArray(array<int, 6>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    array<int, 6> arr = { 12, 11, 13, 5, 6, 7 };
    int arr_size = arr.size();

    cout << "Given array is \n";
    printArray(arr);

    MergeSort().sort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr);
    return 0;

}