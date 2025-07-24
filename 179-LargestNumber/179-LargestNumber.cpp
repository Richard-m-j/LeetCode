// Last updated: 7/24/2025, 8:33:17 AM
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<string> numStrings;
        for(auto&num:nums)
            numStrings.push_back(to_string(num));

        sort(numStrings.begin(),numStrings.end(),[](auto& a, auto& b){
            return a+b > b+a;
        });

        string res = "";
        for(auto& numString: numStrings)
            res += numString;
        if(res[0]=='0')
            return "0";
        return res;
    }
};
