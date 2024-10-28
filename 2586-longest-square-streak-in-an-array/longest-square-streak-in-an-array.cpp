class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        unordered_set<int> s;
        for(int & num: nums)
            s.insert(num);
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])){
                long long square = nums[i];
                int len = 0;
                while(s.count(square)){
                    cout<<square<<" ";
                    s.erase(square);
                    square *= square;
                    len++;
                    res = max(res,len);
                }
            }
        }
        return res>1?res:-1;
    }
};