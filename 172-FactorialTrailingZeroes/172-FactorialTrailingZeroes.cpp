// Last updated: 7/24/2025, 8:33:19 AM
class Solution {
public:
    int trailingZeroes(int n) {

        int res = 0;
        while(n){
            res += n/5;
            n /= 5;
        }
        return res;
    }
};