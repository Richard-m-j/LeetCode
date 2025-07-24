# Last updated: 7/24/2025, 8:30:24 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maxDia = 0
        def getDepth(root):
            if not root:
                return 0
            left = getDepth(root.left)
            right = getDepth(root.right)
        
            self.maxDia = max(left + right, self.maxDia)

            return max(left,right)+1

        getDepth(root)
        return self.maxDia
        
        
        
