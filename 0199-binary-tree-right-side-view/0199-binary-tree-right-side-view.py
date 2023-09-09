# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        rView = [root.val]
        queue = [root]
        while queue:
            nextQueue = []
            for node in queue:
                if node.left:
                    nextQueue += [node.left]
                if node.right:
                    nextQueue += [node.right]
            if nextQueue:
                rView += [nextQueue[-1].val]
            queue = nextQueue
        
        return rView

        

