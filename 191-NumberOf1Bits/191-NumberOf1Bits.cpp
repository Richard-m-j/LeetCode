// Last updated: 7/24/2025, 8:33:12 AM
class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while(n){
            res += n&1;
            n = n>>1;
        }
        return res;
    }
};