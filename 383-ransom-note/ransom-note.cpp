class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26,0);
        for(char& c: ransomNote)
            mp[c-'a']++;
        for(char& c: magazine)
            mp[c-'a']--;
        for(int i=0;i<26;i++)
            if(mp[i]>0)
                return false;
        return true;
    }
};