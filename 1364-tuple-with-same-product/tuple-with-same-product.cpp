class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int res=0;
        for(const pair<int,int>& it: mp){
            if(it.second>1)
                res += it.second*(it.second-1)*4;
        }
        return res;
    }
};
