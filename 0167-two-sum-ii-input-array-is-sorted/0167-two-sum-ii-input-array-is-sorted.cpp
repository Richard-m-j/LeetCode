class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
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