// Last updated: 7/24/2025, 8:26:57 AM
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n<k)
            return false;
        vector<int> mp(26,0);
        for(char&c: s)
            mp[c-'a']++;
        int numOdds=0;
        for(int i=0;i<26;i++)
            if(mp[i]%2)
                numOdds++;
        if(numOdds>k)
            return false;
        return true;
    }
};