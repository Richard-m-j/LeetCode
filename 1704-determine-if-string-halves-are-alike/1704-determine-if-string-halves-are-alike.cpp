int speedUp = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
class Solution {
private:
    unordered_map <char,bool> vowels = {{'A',true},{'E',true},{'I',true},{'O',true},{'U',true},{'a',true},{'e',true},{'i',true},{'o',true},{'u',true}};

public:
    bool halvesAreAlike(string s) {
        int l = 0, r= s.length()-1;
        int numl = 0;
        int numr = 0;
        while(l<r)
        {
            if(vowels[s[l]])
                numl++;
            if(vowels[s[r]])
                numr++;
            l++;
            r--;
        }
        if(numl == numr)
            return true;
        return false;
    }
};