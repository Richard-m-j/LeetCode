class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        map<int,int> mp;
        int res = 0;
        mp[nums[0]] = 0;
        for(int j=1;j<nums.size();j++){
            auto it = mp.upper_bound(nums[j]);

            if (it != mp.begin()) {
                --it;
                res = max(res, j - it->second);
                cout<<j<<" "<<it->second<<endl;
            }
            if(mp.begin()->first > nums[j])
                mp[nums[j]] = j;
        }
        return res;
    }
};