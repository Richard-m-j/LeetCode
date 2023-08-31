class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int curr{0};
        for(int i=0;i<k;i++)
            if(isVowel(s[i]))
                curr++;
        int max=curr;
        for(int i=k;i<n;i++)
            if(isVowel(s[i])&&!isVowel(s[i-k]))
            {
                curr++;
                if(curr>max)
                    max=curr;           
            }
            else if(!isVowel(s[i])&&isVowel(s[i-k]))
                curr--;
        return max;
    }
    bool isVowel(char c)
    {
        switch(c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': return true;
            default :return false;
        }
    }
};