class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += chalk[i];
            if (sum > k) {
                for (int j = 0; j <= i; j++) {
                    k -= chalk[j];
                    if (k < 0)
                        return j;
                }
            }
        }

        int remainingChalk = k % sum;
        for (int i = 0; i < n; i++) {
            remainingChalk -= chalk[i];
            if (remainingChalk < 0)
                return i;
        }
        return 0;
    }
};