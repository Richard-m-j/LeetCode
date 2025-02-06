class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        // sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int res = 0;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++){
                res += (mp[nums[i]*nums[j]]++)*8;
            }
            
        
        // int res=0;
        // for(const pair<int,int>& it: mp)
        //     if(it.second>1)
        //          res += it.second*(it.second-1)*4;
        
        return res;
    }
};
