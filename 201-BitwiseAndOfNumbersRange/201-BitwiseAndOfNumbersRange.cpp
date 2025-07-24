// Last updated: 7/24/2025, 8:33:03 AM
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find common prefix of binary representations of left and right
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // Padding zeros to the right of common prefix
        return left << shift;
    }
};