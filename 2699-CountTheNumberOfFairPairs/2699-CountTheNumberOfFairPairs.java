// Last updated: 7/24/2025, 8:23:25 AM
import java.util.Arrays;

class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        long res = 0; // Should be a long for large results
        Arrays.sort(nums); // Sort the input array
        
        for (int i = 0; i < nums.length; i++) {
            int l = lower_bound(nums, lower - nums[i], i + 1); 
            int r = upper_bound(nums, upper - nums[i], i + 1); 

            res += (r - l);
        }
        return res;
    }
    
    private int lower_bound(int[] nums, int target, int start) {
        int low = start, high = nums.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                high = mid; 
            } else {
                low = mid + 1; 
            }
        }
        return low;
    }
    
    private int upper_bound(int[] nums, int target, int start) {
        int low = start, high = nums.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                high = mid; 
            } else {
                low = mid + 1; 
            }
        }
        return low;
    }
}