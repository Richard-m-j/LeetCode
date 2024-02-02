class Solution {
private: 
    vector<int> mp = {1,11,111,1111,11111,111111,1111111,11111111,111111111,0};
    vector<int> md = {1,12,123,1234,12345,123456,1234567,12345678,123456789,INT_MAX};
public:
    vector<int> sequentialDigits(int low, int high) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        string s = to_string(low);
        int numDigits = s.length() - 1;

        vector<int> res;
        int num = md[numDigits];
        while(num<=high)
        {
            if(num >= low)
                res.push_back(num);
            if(num%10 == 9)
                num = md[++numDigits];
            else
                num += mp[numDigits];
        }
        return res;
    }
};