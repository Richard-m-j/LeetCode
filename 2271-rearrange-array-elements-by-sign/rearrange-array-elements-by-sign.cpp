class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        
        for (int num : nums) {
            if (num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }
        
        nums = {};
        for(int i =0;i<pos.size();i++){
            nums.push_back(pos[i]);
            nums.push_back(neg[i]);
        }
        return nums;
    }
};