# Last updated: 7/24/2025, 8:34:21 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        def getDepth(root):
            if root == None:
                return 0
            left = getDepth(root.left)
            right = getDepth(root.right)
            if left and right:
                return min(left,right) + 1
            if left:
                return left+1
            return right+1
        return getDepth(root)