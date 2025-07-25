// Last updated: 7/24/2025, 8:26:40 AM
class Solution {
public:
    bool mp[128];
    string vowels ="aeiou";
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        for(auto &ch :vowels)
            mp[ch]=true;
        int n=s.length();
        int curr{0};
        int high{0};
        for(int i=0;i<n;i++)
            high=max(high,curr+=mp[s[i]]-(i-k>-1 && mp[s[i-k]]));

        return high;
    }
};