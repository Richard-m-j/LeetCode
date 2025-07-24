# Last updated: 7/24/2025, 8:34:22 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.balance = True
        def getDepth(root):
            if not root:
                return 0
            left = getDepth(root.left)
            right = getDepth(root.right)
            
            if self.balance:
                self.balance = 0 <= abs(left - right) <= 1
            return max(left,right)+1
        
        getDepth(root)
        return self.balance