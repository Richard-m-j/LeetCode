class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Use a min-heap to keep track of the k largest elements
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Insert the first k elements into the min-heap
        for (int i = 0; i < k; ++i) {
            minHeap.push(nums[i]);
        }

        // Compare the remaining elements with the top of the min-heap
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                // If the current element is larger than the smallest element in the heap,
                // replace the smallest element with the current element
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        // The top of the min-heap will be the kth largest element
        return minHeap.top();
    }
};