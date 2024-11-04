class Solution {
public:
    string compressedString(string word) {
        int n=word.length();
        int i=1,count=1;
        char prev = word[0];
        string res = "";
        for(;i<n;i++){
            if(prev == word[i] && count <9)
                count++;
            else{
                res += to_string(count);
                res += prev;
                count = 1;
            }
            prev = word[i];
        }
        res += to_string(count);
        res += prev;
        return res;
    }
};