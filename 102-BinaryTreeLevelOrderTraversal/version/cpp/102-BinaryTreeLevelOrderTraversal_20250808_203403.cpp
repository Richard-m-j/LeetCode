// Last updated: 8/8/2025, 8:34:03 PM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(int i=0;i<nums.size();i++){
            int len = res.size();
            for(int j=0;j<len;j++){
                vector<int> node = res[j];
                node.push_back(nums[i]);
                res.push_back(node);
                node.pop_back();
            }
        }
        return res;
    }
};