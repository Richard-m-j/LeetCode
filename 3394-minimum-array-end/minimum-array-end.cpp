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