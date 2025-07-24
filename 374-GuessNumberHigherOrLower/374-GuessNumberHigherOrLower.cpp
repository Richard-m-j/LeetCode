// Last updated: 7/24/2025, 8:31:30 AM
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            int api = guess(m);
            if(api == 0)
                return m;
            if(api < 0)
                r = m-1;
            else
                l = m+1;
        }
        return 1;
    }
};