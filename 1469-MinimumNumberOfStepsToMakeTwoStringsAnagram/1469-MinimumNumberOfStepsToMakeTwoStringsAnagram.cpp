// Last updated: 7/24/2025, 8:27:13 AM
auto init = []() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        int m = s.length();
        if(n!=m)
            return 0;
        unordered_map <char,int> letterS, letterT;
        for(char & c : s)
            letterS[c]++;
        for(char & c : t)
            letterT[c]++;
        int ans = 0;
        for(const auto & it: letterS)
        {
            int count = it.second - letterT[it.first];
            if(count > 0)
                ans += count;
        }
        return ans;
    }
};