class Solution {
public:
    bool isPowerOfThree(int n) {
        long power = 1;
        if (n == 1)
            return true;
        while (power < n) {
            power *= 3;
            if (power == n)
                return true;
        }
        return false;
    }
};