// Last updated: 7/24/2025, 8:31:51 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool isPowerOfThree(int n) {
        long power = 1;
        if (n == 1)
            return true;
        while (power < n) {
            power *= 3;
            if (power == n)
                return true;
        }
        return false;
    }
};