class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue will store {current element, list index, element index}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        int max_val = INT_MIN;  // Track the maximum value in the current window
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i][0], {i, 0}});  // Initialize with the first element of each list
            max_val = max(max_val, nums[i][0]);
        }
        
        vector<int> res = {-100001, 100001};  // To store the result range
        
        while (true) {
            auto [min_val, indices] = pq.top();  // Get the minimum element
            pq.pop();
            int list_idx = indices.first;
            int elem_idx = indices.second;
            
            // Update the result if we find a smaller range
            if (max_val - min_val < res[1] - res[0]) {
                res[0] = min_val;
                res[1] = max_val;
            }
            
            // Move to the next element in the current list
            if (elem_idx + 1 == nums[list_idx].size()) {
                break;  // If we reach the end of one list, we stop
            }
            
            // Push the next element from the same list into the priority queue
            int next_val = nums[list_idx][elem_idx + 1];
            pq.push({next_val, {list_idx, elem_idx + 1}});
            max_val = max(max_val, next_val);  // Update the maximum value
        }
        
        return res;
    }
};
