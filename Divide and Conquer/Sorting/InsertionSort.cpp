#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayUsingInsertionSort(vector<int>& nums) {
    for (int j = 1; j < nums.size(); j++)
    {
        int key = nums[j];
        int i = j - 1;

        while (i >= 0 && nums[i] > key)
        {
            nums[i + 1] = nums[i];
            i--;
        }
        nums[i + 1] = key;
    }
    return nums;
}

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

    sortArrayUsingInsertionSort(nums);
    printVector(nums);

    return 0;
}
