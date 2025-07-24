// Last updated: 7/24/2025, 8:31:36 AM
int speedUp = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int l = 0, r = num/2;
        while(l<=r)
        {
            long m = l + (r - l) / 2;
            if(m*m == num)
                return true;
            else if (m*m < num)
                l = m + 1;
            else 
                r = m - 1;
        }
        return false;
        
    }
};