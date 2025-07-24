# Last updated: 7/24/2025, 8:29:03 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        return self.getLeaves(root1) == self.getLeaves(root2)

    def getLeaves(self,root):
        if not root:
            return []

        if not root.left and not root.right:
            return [root.val]
        return self.getLeaves(root.left)+self.getLeaves(root.right)