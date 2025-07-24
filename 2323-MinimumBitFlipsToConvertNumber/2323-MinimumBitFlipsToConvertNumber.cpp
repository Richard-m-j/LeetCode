// Last updated: 7/24/2025, 8:24:38 AM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start^goal;
        int res = 0;
        while(x){
            res+=x&1;
            x=x>>1;
        }
        return res;
    }
};