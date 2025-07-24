// Last updated: 7/24/2025, 8:24:29 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,long long success) {
        int numSpells = spells.size(), numPotions = potions.size();
        vector<int> res(numSpells, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < numSpells; i++) {
            int l = 0, r = numPotions - 1;

            while (l <= r) {
                int m = l + (r - l) / 2;   
                if ((static_cast<long long>(potions[m]) * spells[i]) < success)
                    l = m + 1;
                else
                {
                    res[i] += r - m + 1;
                    r = m - 1;
                }
            }
        }
        return res;
    }
};