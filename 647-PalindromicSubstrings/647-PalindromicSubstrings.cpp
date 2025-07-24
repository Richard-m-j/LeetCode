// Last updated: 7/24/2025, 8:29:53 AM
class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        auto palin = [](int i, int j,string &s){
            int count = 0;
            while(i >= 0 && j < s.length() && s[i] == s[j]){
                count++;
                i--;
                j++;
            }
            return count;
        };
        for(int i = 0; i < s.length() ;i++){
           int j = i;
           int odd = palin(i,j , s);
           int even= palin(i , j+1 ,s);
           cnt += (odd + even);
        }
        return cnt;
        
    }
};