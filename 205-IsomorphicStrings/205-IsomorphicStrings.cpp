// Last updated: 7/24/2025, 8:32:58 AM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> mp(128,'\0');
        vector<char> rev(128,'\0');

        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++){
            if(mp[s[i]] == '\0' && rev[t[i]] == '\0'){
                mp[s[i]] = t[i];
                rev[t[i]] = s[i];
            }
            else if(mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
};