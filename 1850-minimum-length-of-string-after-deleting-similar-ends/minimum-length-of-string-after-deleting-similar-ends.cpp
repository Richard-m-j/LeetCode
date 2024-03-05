class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right) {
            if(s[left] == s[right]) {
                int c = s[left];
                left++;
                right--;
                while(left <= right && s[left] == c) left++;
                while(left <= right && s[right] == c) right--;
            }
            else break;
        }

        return right - left + 1;
    }
};