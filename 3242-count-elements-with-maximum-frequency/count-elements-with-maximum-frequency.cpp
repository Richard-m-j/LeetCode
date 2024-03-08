class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int& num: nums)
            mp[num]++;
        int maxFreq = 0, maxFreqCount = 0;
        for(auto& it: mp){
            if(it.second > maxFreq){
                maxFreq = it.second;
                maxFreqCount = it.second;
            }
            else if(it.second == maxFreq)
                maxFreqCount += it.second;
        }
        return maxFreqCount;
    }
};