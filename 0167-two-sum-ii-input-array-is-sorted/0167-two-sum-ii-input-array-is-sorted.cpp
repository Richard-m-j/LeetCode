int speedUp = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;

        while(l<=r)
        {
            int need = target - numbers[l];
            if( need == numbers[r])
                return {l+1,r+1};
            else if(need < numbers[r])
                r--;
            else
                l++;
        }
        return {};
    }
};