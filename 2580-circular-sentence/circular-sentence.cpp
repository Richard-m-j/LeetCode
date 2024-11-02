class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i=0,n=sentence.length();
        char prev = sentence[n-1];
        while(i<n){
            if(prev != sentence[i]){
                // cout<<prev<<" "<<sentence[i]<<" "<<i<<endl;
                return false;
            }
            while(i<n && sentence[i] != ' ')
                i++;
            prev = sentence[i-1];
            i++;
        }
        return true;
    }
};