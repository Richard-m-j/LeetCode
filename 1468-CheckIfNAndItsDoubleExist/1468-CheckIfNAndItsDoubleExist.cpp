// Last updated: 7/24/2025, 8:27:15 AM
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> nums;
        for(int& i:arr){
            if(i%2==0 && nums.count(i/2))
                return true;
            if(nums.count(2*i))
                return true;
            nums.insert(i);
        }
        return false;
    }
};