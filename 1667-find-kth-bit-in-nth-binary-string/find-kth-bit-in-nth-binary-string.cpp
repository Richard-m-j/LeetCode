class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        while(s.length()<k){
            string naxtHalf = "";
            for(int i=s.length()-1;i>=0;i--)
                naxtHalf += s[i] == '0'?'1':'0';
            s = s + "1" + naxtHalf;
        }
        return s[k-1];
    }
};