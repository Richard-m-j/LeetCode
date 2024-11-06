class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp1(26, 0);
        for (char& c : p)
            mp1[c - 'a']++;
        int n = s.length();
        int m = p.length();
        vector<int> res;
        // for(int i=0;i<m;i++){
        //     if(mp1[s[i]-'a']>0){
        //         mp1[s[j] - 'a']--;
        //         numChars--;
        //     }
        // }
        for(int i=0;i<n-m+1;i++){
            vector<int> mp2(mp1.begin(),mp1.end());
            int numChars = m;
            for(int j=i;j<i+m;j++){
                if(mp2[s[j] - 'a']>0){
                    mp2[s[j] - 'a']--;
                    numChars--;
                }
                else
                    break;
            }
            // cout<<i<<" "<<numChars<<endl;
            if(!numChars)
                res.push_back(i);
        }
        return res;
    }
};