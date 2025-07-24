// Last updated: 7/24/2025, 8:25:50 AM
class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int left = 0, right = s.length() - 1;

        while(left < right) {
            if(s[left] == s[right]) {
                int c = s[left];
                while(left <= right && s[left] == c) left++;
                while(left <= right && s[right] == c) right--;
            }
            else break;
        }

        return right - left + 1;
    }
};