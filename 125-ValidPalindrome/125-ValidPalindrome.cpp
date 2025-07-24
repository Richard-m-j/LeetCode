// Last updated: 7/24/2025, 8:34:05 AM
class Solution {
public:
    bool isPalindrome(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
          
        int l=0,r=s.length()-1;
        while(l<=r){
            cout<<s[l]<<" "<<s[r]<<endl;
            if(!isalpha(s[l]) && !isdigit(s[l])){
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r])){
                r--;
                continue;
            }
            
            if(tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};