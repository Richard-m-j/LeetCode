// Last updated: 7/24/2025, 8:22:08 AM
class Solution {
public:
    int maxDifference(string s) {
        vector<int> mp(26,0);
        for(char& c: s){
            mp[c-'a']++;
        }
        int odd=0,even=s.length();
        for(int i=0;i<26;i++){
            if(!mp[i])
                continue;
            if(mp[i]%2)
                odd = max(odd,mp[i]);
            else
                even = min(even,mp[i]);
        }
        int res = odd - even;
        return odd - even;
    }
};