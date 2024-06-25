# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        from collections import deque
        if not root:
            return []
        traversal = []
        q1 = deque([root])
        while len(q1):
            q2 = deque()
            level = []
            while len(q1):
                item = q1.popleft()
                level.append(item.val)
                if item.left:
                    q2.append(item.left)
                if item.right:
                    q2.append(item.right)
            traversal.append(level)
            q1 = q2
        return traversal
