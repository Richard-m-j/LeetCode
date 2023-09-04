class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        int min =  200000, max = -200000;
        for (int i = 0; i < nums.size(); i++) {
            if (min > nums[i]) min = nums[i];
            if (max < nums[i]) max = nums[i];    
        }
        const int range = -min, size = max-min+1;
        char store[size]; 
        for (int i = 0; i < size; i++) store[i] = 0;
        for (int i = 0; i < nums.size(); i++) if (store[nums[i]+range] < 3) store[nums[i]+range]++; 
        int len = 0;
        for (int i = 0, j = 0; i < size; i++) {
            if (store[i] > 0) {
                nums[j++] = i-range;
                len++;
            }
        }
        vector<int>& unique = nums;
        vector<int> soln(3,0);
        if (unique[0] > 0 || unique[len-1] < 0) return ans;
        else if (len == 1) {
            if (unique[0]==0 && store[range]>2) ans.push_back(soln);
            return ans;
        }
        const int high = unique[len-1], zero = store[range];
        for (int i = 0; i < len; i++) {
            int a = unique[i];
            if (a > 0) break;
            int j = (store[a+range] > 1) ? i : i+1;
            for (; j < len; j++) {
                int b = unique[j];
                int c = -a-b;
                if (b > -a/2) break;
                else if (c > high || c < b) continue;
                else if (c == b) {
                    if ((c==0 && zero>=3) || (c!=0 && store[c+range]>=2)) {
                        soln[0] = a;
                        soln[1] = b;
                        soln[2] = c;
                        ans.push_back(soln);
                    }
                } 
                else {
                    if (store[c+range]) {
                        soln[0] = a;
                        soln[1] = b;
                        soln[2] = c;
                        ans.push_back(soln);
                    }
                }
            }
        }
        return ans;
    }
};