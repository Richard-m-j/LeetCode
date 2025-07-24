// Last updated: 7/24/2025, 8:31:33 AM
class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};