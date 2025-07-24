// Last updated: 7/24/2025, 8:25:06 AM
class Solution {
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int atMostK(string &s,int k){
        int n = s.length(),l=0;
        int res = 0;
        unordered_map <char,int> mp;
        for(int r=0;r<n;r++){
            if(!isVowel(s[r])){
                l=r+1;
                mp.clear();
                continue;
            }
            mp[s[r]]++;
            while(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            res += r-l+1;
        }
        return res;
    }
public:
    int countVowelSubstrings(string word) {
        return atMostK(word,5) - atMostK(word,4);
    }
};