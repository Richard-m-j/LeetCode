class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> sumsSet;
        vector<int> sumsVector;
        long long totalSum = accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)
            return false;
        long long target = totalSum/2;
        sumsSet.insert(0);
        sumsVector.push_back(0);
        for(int i=0;i<nums.size();i++){
            int len = sumsVector.size();
            for(int j=0;j<len;j++){
                if(sumsVector[j]+nums[i] == target)
                    return true;
                if(!sumsSet.count(sumsVector[j]+nums[i])){
                    sumsVector.push_back(sumsVector[j] + nums[i]);
                    sumsSet.insert(sumsVector[j] + nums[i]);
                }
            }
        }
        return false;
    }
};