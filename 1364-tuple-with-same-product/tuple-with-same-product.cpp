static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int res = 0;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                res += (mp[nums[i]*nums[j]]++)*8;
            
            
        
        // int res=0;
        // for(const pair<int,int>& it: mp)
        //     if(it.second>1)
        //          res += it.second*(it.second-1)*4;
        
        return res;
    }
};
