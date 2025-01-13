class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        x = 0
        mp = {}

        # Count the frequency of each character
        for char in s:
            mp[char] = mp.get(char, 0) + 1

        # Calculate the number of characters to be removed
        for f in mp.values():
            x += (f - 1) if (f % 2 == 1) else (f - 2)

        return n - x