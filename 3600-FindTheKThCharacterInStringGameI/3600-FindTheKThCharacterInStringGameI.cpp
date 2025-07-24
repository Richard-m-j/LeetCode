// Last updated: 7/24/2025, 8:22:09 AM
class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length() <k){
            // cout<<s<<endl;
            int n = s.length();
            for(int i=0;i<n;i++)
                s += char('a' + (s[i]-'a'+1)%26);
        }
        return s[k-1];
    }
};