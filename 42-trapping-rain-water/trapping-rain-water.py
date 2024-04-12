class Solution:
    def trap(self, height: List[int]) -> int:
        leftMax, rightMax = 0, 0
        rightMaxArr, leftMaxArr = [0] * len(height), [0] * len(height)
        waterCanTrap = 0

        for idx in range(len(height)):
            leftMax = max(leftMax, height[idx])
            leftMaxArr[idx] = leftMax

        for idx in reversed(range(len(height))):
            rightMax = max(rightMax, height[idx])
            rightMaxArr[idx] = rightMax

        for idx in range(len(height) - 1):
            waterCanTrap += min(leftMaxArr[idx], rightMaxArr[idx]) - height[idx]
        
        return waterCanTrap