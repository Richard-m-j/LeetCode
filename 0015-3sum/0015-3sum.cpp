class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) 
            return ans;
        int min =  INT_MAX, max = INT_MIN;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (min > nums[i]) 
                min = nums[i];
            if (max < nums[i]) 
                max = nums[i];    
        }
        const int range = -min, size = max-min+1;
        char store[size]; 
        for (int i = 0; i < size; i++) 
            store[i] = 0;
        for (int i = 0; i < nums.size(); i++) 
            if (store[nums[i]+range] < 3) 
                store[nums[i]+range]++; 
        int len = 0;
        for (int i = 0; i < size; i++) 
            if (store[i] > 0) 
                nums[len++] = i-range;


        if (nums[0] > 0 || nums[len-1] < 0) 
            return ans;
        else if (len == 1) 
        {
            if (nums[0]==0 && store[range]>2) 
                ans.push_back({0,0,0});
            return ans;
        }
        const int high = nums[len-1], zero = store[range];
        for (int i = 0; i < len; i++) 
        {
            int a = nums[i];
            if (a > 0) break;
            int j = (store[a+range] > 1) ? i : i+1;
            for (; j < len; j++) 
            {
                int b = nums[j];
                int c = -a-b;
                if (b > -a/2) break;
                else if (c > high || c < b) 
                    continue;
                else if (c == b) 
                {
                    if ((c==0 && zero>=3) || (c!=0 && store[c+range]>=2)) 
                        ans.push_back({a,b,c});
                    
                } 
                else 
                {
                    if (store[c+range]) 
                        ans.push_back({a,b,c});

                }
            }
        }
        return ans;
    }
};