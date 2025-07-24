// Last updated: 7/24/2025, 8:22:15 AM
class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int consonantCount = 0;
            unordered_set<char> vowels;
            for (int j = i; j < n; j++) {
                if (!isVowel(word[j])) {
                    consonantCount++;
                }
                else
                    vowels.insert(word[j]);
                if (consonantCount == k && vowels.size() == 5) {
                    result++;
                }
                if (consonantCount > k) {
                    break;
                }
            }
        }

        return result;
    }
};