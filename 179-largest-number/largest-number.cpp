class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;
        bool foundZero = false;
        for(auto&num:nums)
            numStrings.push_back(to_string(num));
        sort(numStrings.rbegin(),numStrings.rend(),[](auto& a,auto& b){
            int k=0;
            for(int i=0,j=0;i<a.length()&&j<b.length();i=(i+1)%a.length(),j=(j+1)%b.length()){
                if(k>2*a.length()||k>2*b.length())
                    return a.length()>b.length();
                if(a[i]!=b[j])
                    return a[i]<b[j];
                k++;
            }
            return false;
        });

        string res = "";
        for(auto& numString: numStrings)
            res += numString;
        if(res[0]=='0')
            return "0";
        return res;
    }
};