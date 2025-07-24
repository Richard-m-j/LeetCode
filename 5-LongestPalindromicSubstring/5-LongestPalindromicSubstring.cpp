// Last updated: 7/24/2025, 8:36:50 AM
class Solution {
public:
    string longestPalindrome(string s) {
        const int m=s.length();
        int start=0, len=1, mid=0;
        while(mid + len/2 < m){
            int l = mid, r = mid;
            while(r < m-1 && s[r] == s[r+1]) 
                ++r;
            mid = r + 1;
            while(l>0 && r<m-1 && s[l-1]==s[r+1]) 
            {   
                --l;
                ++r;
            }
            if(r - l + 1 > len)
            {
                start = l;
                len = r - l + 1;
            }
        }
        return s.substr(start, len);
    }
};