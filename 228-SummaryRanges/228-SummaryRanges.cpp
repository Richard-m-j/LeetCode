// Last updated: 7/24/2025, 8:32:37 AM
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size())
            return {};
        vector<string> res;
        int start = nums[0],end = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==end+1){
                end++;
            }
            else{
                if(start!=end)
                    res.push_back(to_string(start) + "->" + to_string(end));
                else
                    res.push_back(to_string(start)); 
                start = end = nums[i];    
            }
        }
        if(start!=end)
            res.push_back(to_string(start) + "->" + to_string(end));
        else
            res.push_back(to_string(start));
        return res;
    }
};