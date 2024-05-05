/**
 * Given two sparse vectors, compute their dot product.
 * 
 * Implement class SparseVector:
 *      SparseVector(nums) Initializes the object with the vector nums
 *      dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
 * 
 * A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.
 * 
 * Follow up: What if only one of the vectors is sparse?
 * 
 * Example 1:
 * Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
 * Output: 8
 * Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
 * v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
 * 
 * Example 2:
 * Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
 * Output: 0
 * Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
 * v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
 * 
 * Example 3:
 * Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
 * Output: 6
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                mapNonZeroElements[i] = nums[i];
                vectorPairNonZeroElements.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProductInefficient(SparseVector& vec) {
        int result = 0;

        for (int i = 0; i < sparseVec.size(); i++) {
            result += vec.sparseVec[i] * sparseVec[i];
        }
        return result;
    }

    // Return the dotProduct of two sparse vectors
    int dotProductUsingMap(SparseVector& vec) {
        int result = 0;

        // Iterate on the map of the current vector
        for (auto elem : this->mapNonZeroElements) {
            // Search the key(index) from the current vector in the map of the passed vector
            // If there exists any, then we have a non-zero product
            if (vec.mapNonZeroElements.find(elem.first) != vec.mapNonZeroElements.end()) {
                result += this->mapNonZeroElements[elem.first] * vec.mapNonZeroElements[elem.first];
            }
        }
        return result;
    }

    // Return the dotProduct using vector<pair<int, int>> and two pointers
    int dotProduct(SparseVector& vec) {
        int result = 0;
        int i = 0;
        int j = 0;

        // Iterate until either of them has been exhausted
        while (i < this->vectorPairNonZeroElements.size() && j < vec.vectorPairNonZeroElements.size()) {
            // index matches for non-zero elements.
            // Candidate found
            if (this->vectorPairNonZeroElements[i].first == vec.vectorPairNonZeroElements[j].first) {
                result += this->vectorPairNonZeroElements[i].second * vec.vectorPairNonZeroElements[j].second;
                i++;
                j++;
            } else if (this->vectorPairNonZeroElements[i].first < vec.vectorPairNonZeroElements[j].first) {
                i++;    // increment the smaller pointer
            } else
                j++;
        }
        return result;
    }

private:
    vector<int> sparseVec;
    unordered_map<int, int> mapNonZeroElements; // {index, valueAtIndex}
    vector<pair<int, int>> vectorPairNonZeroElements; // <{index, valueAtIndex}>
};

void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 0, 0, 2, 3};
    vector<int> nums2 = {0, 3, 0, 4, 0};

    SparseVector v1(nums1);
    SparseVector v2(nums2);

    cout << "Test case 1: " << endl;
    printVector(nums1);
    printVector(nums2);
    cout << "Dot Product: " << v1.dotProduct(v2) << endl;

    vector<int> nums3 = {0, 1, 0, 0, 0};
    vector<int> nums4 = {0, 0, 0, 0, 2};

    SparseVector v3(nums3);
    SparseVector v4(nums4);

    cout << "Test case 2: " << endl;
    printVector(nums3);
    printVector(nums4);
    cout << "Dot Product: " << v3.dotProduct(v4) << endl;

    vector<int> nums5 = {0, 1, 0, 0, 2, 0, 0};
    vector<int> nums6 = {1, 0, 0, 0, 3, 0, 4};

    SparseVector v5(nums5);
    SparseVector v6(nums6);

    cout << "Test case 3: " << endl;
    printVector(nums5);
    printVector(nums6);
    cout << "Dot Product: " << v5.dotProduct(v6) << endl;

    return 0;
}

