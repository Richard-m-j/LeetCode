class Solution {
public:
    bool isAnagram(string s, string t) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(s.length() != t.length())
            return false;
        unordered_map<char,int> m1,m2;
        for(auto &c: s)
            m1[c]++;
        for(auto &c: t)
            m2[c]++;
        for(auto &it: m1)
            if(it.second != m2[it.first])
                return false;
        return true;
    }
};