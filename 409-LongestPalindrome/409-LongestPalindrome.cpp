// Last updated: 7/24/2025, 8:31:07 AM
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(128,0);

        for(auto& c: s)
            mp[c]++;
        int res = 0;
        bool isOdd = false;
        for(int i=0;i<128;i++){
            if(!isOdd && mp[i]%2)
                isOdd = true;
            res += mp[i] - mp[i]%2;
        }
        return res + isOdd;          
    }
};