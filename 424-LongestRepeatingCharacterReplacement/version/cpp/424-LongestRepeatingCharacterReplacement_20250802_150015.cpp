// Last updated: 8/2/2025, 3:00:15 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxF = 0;
        vector<int> mp(26, 0);
        for (int r = 0; r < s.length(); r++) {
            mp[s[r] - 'A']++;
            maxF = max(maxF,mp[s[r]-'A']);

            if(r-l+1-maxF>k){
                mp[s[l]-'A']--;
                l++;
            }
        }
        return s.length() - l;
    }
};