#include <string>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tmap(128, 0); // ASCII characters
        int m = s.length(), n = t.length();
        for (char& c : t)
            tmap[c]++;

        int count = n;
        int minLen = INT_MAX;
        string res = "";

        for (int r = m - 1, l = r; l >= 0; --l) {
            if (tmap[s[l]]-- > 0)
                count--;
            while (count == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    res = s.substr(l, minLen);
                }
                if (++tmap[s[r]] > 0)
                    count++;
                r--;
            }
        }
        return res;
    }
};
