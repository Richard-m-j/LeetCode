class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int vec1[26]={};
        int vec2[26]={};
        for(char i:word1){
            vec1[i-'a']++;
        }
        for(char i:word2){
            vec2[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(vec1[i]>0 && vec2[i]==0 || (vec2[i]>0 && vec1[i]==0)){
                return false;
            }
        }
        sort(vec1,vec1+26);
        sort(vec2,vec2+26);
        for(int i=0;i<26;i++){
            if(vec1[i]!=vec2[i]){
                return false;
            }
        }
        return true;
    }
};