class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0;
        int l=0,r=0,n=arr.size();
        vector<int> nums(arr.begin(),arr.end());
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++)
            if(nums[i]!=nums[i-1])
                mp[nums[i]] = i;
        
        for(int i=0;i<n;i++){
            r=max(mp[arr[i]],r);
            mp[arr[i]]++;
            if(r==i)
                res++;
        }
        return res;
    }
};