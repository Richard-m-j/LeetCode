// Last updated: 7/24/2025, 8:27:18 AM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res =0 ;
        for(int& num: nums){
            string numString= to_string(num);
            if(!(numString.length()%2))
                res++;
        }
        return res;
    }
};