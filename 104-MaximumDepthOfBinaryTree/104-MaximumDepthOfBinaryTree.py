# Last updated: 7/24/2025, 8:34:34 AM
class Solution:          
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        return 1+ max(self.maxDepth(root.left),self.maxDepth(root.right))