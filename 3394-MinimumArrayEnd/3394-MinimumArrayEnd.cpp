// Last updated: 7/24/2025, 8:22:33 AM
class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        long long pos = 1;
        n--;
        while(n){
            if(!(x& pos)){
                res |= (n&1)*pos;
                n >>= 1;
            }
            pos<<=1;
        }
        return res;
    }
};