class Solution {
public:
    std::array<bool, 128> initializeIsLowerVowel() 
    {
    std::array<bool, 128> isLowerVowel = {}; // Initialize all to false

    // Initialize lowercase vowels to true
    isLowerVowel['a'] = true;
    isLowerVowel['e'] = true;
    isLowerVowel['i'] = true;
    isLowerVowel['o'] = true;
    isLowerVowel['u'] = true;

    return isLowerVowel;
    }
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        std::array<bool, 128> mp = initializeIsLowerVowel();
        int n=s.length();
        int curr{0};
        int high{0};
        for(int i=0;i<n;i++)
            high=max(high,curr+=mp[s[i]]-(i-k>-1 && mp[s[i-k]]));

        return high;
    }
};