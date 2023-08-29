class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=k)
                continue;
            if(umap.find(k-nums[i]) == umap.end()||umap[k-nums[i]]==0)
                umap[nums[i]]++;
            else
            {
                umap[k-nums[i]]--;
                count++;
            }
        }
        return count;
    }
};