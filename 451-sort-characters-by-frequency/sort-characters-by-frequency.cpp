class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        
        for (char c : s)
            freqMap[c]++;
        
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        sort(freqVec.begin(), freqVec.end(), customKeySort);
        
        string res = "";
        for (auto& [ch, freq] : freqVec) {
            res += string(freq, ch);
        }
        
        return res;
    }
    
private:
    static bool customKeySort(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; 
    }
};
