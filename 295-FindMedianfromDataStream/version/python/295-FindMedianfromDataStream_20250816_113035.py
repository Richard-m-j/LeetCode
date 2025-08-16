# Last updated: 8/16/2025, 11:30:35 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        valid = True
        def minMaxNode(root: TreeNode):
            leftMin,leftMax = root.val,root.val
            leftValid = True
            if root.left:
                leftMin,leftMax,leftValid = minMaxNode(root.left)
                if leftValid and root.val == leftMax:
                    leftValid = False
            
            rightMin,rightMax = root.val,root.val
            rightValid = True
            if root.right:
                rightMin,rightMax,rightValid = minMaxNode(root.right)
                if rightValid and root.val == rightMin:
                    rightValid = False
            
            print(leftMin,' ',leftMax,' ',root.val,' ',rightMin,' ',rightMax)
            nodeValid = True
            if leftMax > root.val or rightMin < root.val:
                nodeValid = False
            valid = nodeValid and leftValid and rightValid
            print(valid)
            return min(leftMin,leftMax,rightMin,rightMax,root.val),max(leftMin,leftMax,rightMin,rightMax,root.val),valid
        l,r, res = minMaxNode(root)
        return res
