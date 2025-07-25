// Last updated: 7/24/2025, 8:32:14 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(s.length() != t.length())
            return false;
        vector<int> count(26,0);
        for(auto&c: s)
            count[c-'a']++;
        for(auto&c:t)
            count[c-'a']--;
        for(int i=0;i<26;i++)
            if(count[i] != 0)
                return false;
        return true;
    }
};