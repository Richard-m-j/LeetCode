# Last updated: 7/24/2025, 8:28:11 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        queue = [root]
        maxLevelSum = root.val
        maxLevel = 1
        level = 1
        while queue:
            nextQueue = []
            levelSum = 0
            
            for node in queue:
                if node.left:
                    nextQueue += [node.left]
                if node.right:
                    nextQueue += [node.right]
                levelSum += node.val

            if levelSum > maxLevelSum:
                maxLevelSum = levelSum
                maxLevel = level
            queue = nextQueue
            level += 1

        
        return maxLevel
