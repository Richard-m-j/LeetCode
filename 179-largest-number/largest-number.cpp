class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        bool foundZero = false;
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
