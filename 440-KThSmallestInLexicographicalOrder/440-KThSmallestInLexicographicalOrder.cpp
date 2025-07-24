// Last updated: 7/24/2025, 8:30:52 AM
class Solution {
private:
    int countNumbersWithPrefix(int prefix, int n) {
        long long firstNumber = prefix, nextNumber = prefix + 1;
        int res = 0;

        while (firstNumber <= n) {
            res += static_cast<int>(min(n + 1LL, nextNumber) - firstNumber);
            firstNumber *= 10;
            nextNumber *= 10;
        }

        return res;
    }
public:
    int findKthNumber(int n, int k) {
        int currentPrefix = 1;
        --k;  
        
        while (k > 0) {
            int count = countNumbersWithPrefix(currentPrefix, n);
            if (k >= count) {
                ++currentPrefix;  
                k -= count;
            } else {
                currentPrefix *= 10;  
                --k;
            }
        }
        
        return currentPrefix;
    }
};