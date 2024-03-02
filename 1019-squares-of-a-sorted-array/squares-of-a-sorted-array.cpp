class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> squares(nums.size());

        for (int i=nums.size()-1; i>=0; i--) {
            if (abs(nums[l]) >= abs(nums[r])) {
                squares[i] = nums[l]*nums[l];
                l++;
            }
            else {
                squares[i] = nums[r]*nums[r];
                r--;
            }
        }

        return squares;
    }
};