#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // Step 1: Create a heap of pairs {value, index} to track values and their positions
        vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back({nums[i], i});
        }

        // Step 2: Transform the vector into a min-heap
        make_heap(heap.begin(), heap.end(), greater<>());

        // Step 3: Process k smallest elements
        while (k--) {
            // Extract the minimum element from the heap
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, index] = heap.back();
            heap.pop_back();

            // Update the corresponding value in the array
            nums[index] *= multiplier;

            // Reinsert the updated value into the heap
            heap.push_back({nums[index], index});
            push_heap(heap.begin(), heap.end(), greater<>());
        }

        // Step 4: Return the updated array
        return nums;
    }
};
