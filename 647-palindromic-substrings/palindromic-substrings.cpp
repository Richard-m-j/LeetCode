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
           int oddLengthVale = palin(i,j , s);
           int evenLengthVale= palin(i , j+1 ,s);
           cnt += (oddLengthVale + evenLengthVale);
        }
        return cnt;
        
    }
};