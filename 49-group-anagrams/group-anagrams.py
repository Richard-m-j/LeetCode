class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for word in strs:
            chars = [0]*26
            for c in word:
                chars[ord(c)-97] += 1
            mp[tuple(chars)].append(word)
        return list(mp.values())
