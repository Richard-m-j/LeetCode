class Solution {
public:
    string addBinary(string a, string b) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string res = "";
        int carry = 0,sum;
        int i=a.length()-1,j=b.length()-1;
        while(i>=0 || j>=0 || carry){
            sum = 0;
            if(i>=0)
                sum += a[i] - '0';
            if(j>=0)
                sum += b[j] - '0';
            i--,j--;

            sum += carry;
            res = char(sum % 2 +'0') + res;
            carry = sum / 2;
        }
        return res;
    }
};