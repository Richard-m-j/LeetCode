# Last updated: 8/16/2025, 8:19:13 PM
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        fmap=Counter(nums)
        sortedNums = sorted(fmap, key=fmap.get, reverse=True)
        return sortedNums[:k]
