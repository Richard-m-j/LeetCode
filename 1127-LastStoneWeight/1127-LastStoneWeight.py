# Last updated: 7/24/2025, 8:28:02 AM
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        import heapq
        maxStones = [-x for x in stones]
        heapq.heapify(maxStones)

        while len(maxStones) > 1:
            y = heapq.heappop(maxStones)
            x = heapq.heappop(maxStones)
            heapq.heappush(maxStones, y-x)
        if len(maxStones) == 1:
            return -maxStones[0]
        return 0
