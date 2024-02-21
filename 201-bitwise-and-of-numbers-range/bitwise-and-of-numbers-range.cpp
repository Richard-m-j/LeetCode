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