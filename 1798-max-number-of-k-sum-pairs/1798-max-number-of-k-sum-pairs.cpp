class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // ios_base::sync_with_stdio(false);
        // unordered_map<int,int> umap;
        // int n=nums.size();
        // int count=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]>=k)
        //         continue;
        //     if(umap.find(k-nums[i]) == umap.end()||umap[k-nums[i]]==0)
        //         umap[nums[i]]++;
        //     else
        //     {
        //         umap[k-nums[i]]--;
        //         count++;
        //     }
        // }
        // return count;
        ios_base::sync_with_stdio(false);
        sort(nums.begin(),nums.end());
        int i{0},j=nums.size()-1;
        int count{0};
        while(i<j)
        {
            if(nums[i]+nums[j]==k)
                count++,i++,j--;
            else if(nums[i]+nums[j]<k)  
                i++;
            else  
                j--;
        }
        return count;
    }
};