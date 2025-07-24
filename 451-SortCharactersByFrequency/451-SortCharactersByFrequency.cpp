// Last updated: 7/24/2025, 8:30:45 AM
class Solution {
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<char, int> freqMap;
        
        for (char c : s)
            freqMap[c]++;
        
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), customKeySort);
        
        string res = "";
        for (auto& [c, f] : freqVec) 
            res += string(f, c);
        
        return res;
    }
    
private:
    static bool customKeySort(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; 
    }
};
