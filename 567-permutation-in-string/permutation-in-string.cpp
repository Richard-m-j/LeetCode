class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m)
            return false;
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for (int i = 0; i < n; i++) {
            mp1[s1[i] - 'a']++;
        }
        int numChars = 0,start=0;

        for (int i = 0; i < m; i++) {
            mp2[s2[i]-'a']++;
            numChars++;
            while(mp2[s2[i]-'a']>mp1[s2[i]-'a']){
                mp2[s2[start]-'a']--;
                start++;
                numChars--;
            }
            cout<<numChars<<" ";
            if(numChars==n)
                return true;
        }
        return false;
    }
};