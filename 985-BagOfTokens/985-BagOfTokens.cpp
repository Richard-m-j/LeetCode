// Last updated: 7/24/2025, 8:28:29 AM
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());

        int l=0,r=tokens.size()-1;
        int maxScore = 0,currentScore =0;
        while(l<=r){
            if(tokens[l]<=power){
                //face-up
                power -= tokens[l++];
                maxScore = max(maxScore,++currentScore);
            }
            else if(currentScore >= 1){
                //face-down
                currentScore--;
                power += tokens[r--];
            }
            else
                break;
        }
        return maxScore;
    }
};