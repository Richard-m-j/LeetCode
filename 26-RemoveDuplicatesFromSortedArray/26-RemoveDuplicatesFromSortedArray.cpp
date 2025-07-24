// Last updated: 7/24/2025, 8:36:14 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=-1;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){
                
                k++;
            }
            nums[k] = nums[i];
            mp[nums[i]] = i;    
        }
        return k+1;
    }
};