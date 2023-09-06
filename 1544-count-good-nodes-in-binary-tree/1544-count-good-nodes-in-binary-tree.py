# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def recCheck(root,big): 
            if not root:
                return 0
            good = True
            if root.val < big:
                good = False
            else:
                big = root.val
            leftCount = recCheck(root.left,big)
            rightCount = recCheck(root.right,big)
            
            return leftCount + rightCount + good

        return recCheck(root, float('-inf'))