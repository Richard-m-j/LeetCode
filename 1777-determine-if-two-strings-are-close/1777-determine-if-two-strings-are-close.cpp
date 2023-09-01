class Solution {
public:
    
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int f1[26]={};
        int f2[26]={};
        if(word1.length()!=word2.length())
            return false;
        
        for(char i: word1)
            f1[i-'a']++;

        for(char i: word2)
            f2[i-'a']++;

        for(int i=0;i<26;i++)
            if(f1[i]>0&&!f2[i]||f2[i]>0&&!f1[i])
                return false;
        
        sort(f1,f1+26);
        sort(f2,f2+26);

        // for(int i=0;i<26;i++)
        //     if(f1[i]!=f2[i])
        //         return false;

        return memcmp(f1, f2, sizeof(f1)) == 0;
    }
};