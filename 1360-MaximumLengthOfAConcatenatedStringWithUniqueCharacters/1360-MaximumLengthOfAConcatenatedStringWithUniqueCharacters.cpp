// Last updated: 7/24/2025, 8:27:31 AM
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength = 0;
        vector<string> currentSubsequence;

        backtrack(arr, 0, currentSubsequence, maxLength);

        return maxLength;
    }

private:
    void backtrack(const vector<string>& arr, int start, vector<string>& currentSubsequence, int& maxLength) {
        // Check if the current subsequence has unique characters
        unordered_set<char> charSet;
        for (const string& str : currentSubsequence) {
            for (char ch : str) {
                if (charSet.count(ch) > 0) {
                    return;  // Not a valid subsequence, contains duplicate characters
                }
                charSet.insert(ch);
            }
        }

        // Calculate the length of the current subsequence
        int currentLength = 0;
        for (const string& str : currentSubsequence) {
            currentLength += str.length();
        }

        // Update the maximum length if the current subsequence is longer
        maxLength = max(maxLength, currentLength);

        // Explore all possible subsequences by choosing or not choosing the current string
        for (int i = start; i < arr.size(); ++i) {
            currentSubsequence.push_back(arr[i]);
            backtrack(arr, i + 1, currentSubsequence, maxLength);
            currentSubsequence.pop_back();
        }
    }
};