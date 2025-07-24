// Last updated: 7/24/2025, 8:22:14 AM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> numSet;
        vector<int> res;
        for(int& num:nums){
            if(numSet.find(num)!=numSet.end()){
                res.push_back(num);
            }
            numSet.insert(num);
        }
        return res;
    }
};