// Last updated: 7/24/2025, 8:32:33 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        return n == pow(2,floor(log2(n)));
    }
};