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
        int high{0};
        for(int i=0,curr{0};i<n;i++)
            high=max(high,curr+=mp[s[i]]-(i-k>-1 && mp[s[i-k]]));

        return high;
    }
};