class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(),tokens.end());

        int l=0,r=tokens.size()-1;
        int maxScore = 0,currentScore =0;
        while(l<=r){
            if(tokens[l]<=power){
                //face-up
                currentScore++;
                power -= tokens[l];
                l++;
            }
            else if(currentScore >= 1){
                //face-down
                currentScore--;
                power += tokens[r];
                r--;
            }
            else
                break;
            maxScore = max(maxScore,currentScore);
        }
        return maxScore;
    }
};