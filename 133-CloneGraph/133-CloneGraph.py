# Last updated: 7/24/2025, 8:34:01 AM
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        graph = {node.val: Node(node.val)}
        stack = [node]
        visited = set()
        
        while stack:
            current = stack.pop()
            if current.val in visited:
                continue
            cloneCurrent = graph[current.val]
            for neighbor in current.neighbors:
                if neighbor.val not in graph:
                    clone = Node(val = neighbor.val)
                    graph[neighbor.val] = clone
                stack.append(neighbor)
                cloneCurrent.neighbors.append(graph[neighbor.val])
            visited.add(current.val)
            print(current.val)
            for i in cloneCurrent.neighbors:
                print(i.val,end = " ")
            print()
        return graph[node.val]
