// Last updated: 7/24/2025, 8:36:44 AM
class Solution {
public:
    bool isPalindrome(int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(x<0)
            return false;
        long n = x, r = 0;
        while(n){
            r = r*10 + n%10;
            n/=10;
        }
        return r == x;
    }
};