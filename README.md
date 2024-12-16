Problem : Final Array State After K Multiplication Operations I
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]
Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5


---------- SOLUTION ------------------------
Overview
We need to perform k operations on an integer array. In each operation, we identify the smallest value, multiply it by a given multiplier, and then replace the original value with the new one. The main challenge is to efficiently track and update the smallest element in the array.

This kind of problem often arises in resource management scenarios, where tasks or items need to be prioritized or adjusted based on criteria such as price or urgency.

Used approach: Heap-Optimized K Minimum Value Multiplication
Intuition
In the previous approach, we were doing full array scans to find the minimum element. To optimize this, we can use a data structure that is designed for quickly retrieving and modifying the smallest element: a heap. A heap allows us to access the smallest element in constant time and efficiently supports removing and inserting elements with logarithmic time complexity.

To implement this, we can start by creating a list where each element is paired with its index in the original array. The index is crucial because after modifying an element, we need to know where to place the updated value in the array. This way, we can keep track of the original position of each element while sorting them based on their values.

Once the list is created, we convert it into a heap. In a heap, the smallest element can be accessed and removed efficiently. For each of the k operations, we need to perform 3 steps:

Pop the smallest element from the heap: This gives us both the value of the smallest element and its index in the original array.
Multiply the value by the multiplier: Update the array at the corresponding index with this new value.
Push the modified value back into the heap: Include its index so that it can be considered for future operations.
After completing all k operations, we return the modified array.
Let N be the length of nums.
