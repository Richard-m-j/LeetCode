// Last updated: 7/24/2025, 8:36:38 AM
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char,int> chart = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n;i++)
        {
            if(i<n-1 && chart[s[i]] < chart[s[i+1]])
                ans -= chart[s[i]];
            else
                ans += chart[s[i]];
        }
        return ans;
    }    
};