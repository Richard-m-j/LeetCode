int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int mySqrt(int x) {
        int l =0, r= x/2;
        long m;
        if(x == 1)
            return 1;
        while(l<=r)
        {
            m = l + (r-l)/2;
            if(m*m == x)
                return m;
            else if(m*m < x)
                l = m+1;
            else
                r = m-1;
        }

        return l-1;
    }
};