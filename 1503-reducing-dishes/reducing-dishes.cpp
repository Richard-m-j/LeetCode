class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        int maxCoeff = 0, sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            int currentCoeff = maxCoeff + sum + satisfaction[i];
            if (currentCoeff >= maxCoeff) {
                maxCoeff = currentCoeff;
                sum += satisfaction[i];
            }
            else
                break;
        }
        return maxCoeff;
    }
};