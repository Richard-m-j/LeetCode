# Last updated: 7/24/2025, 8:31:13 AM
class Solution:
    def calcEquation(self, equations, values, queries):
        def find(node):
            if node != parents[node][0]:
                p, v = find(parents[node][0])
                parents[node] = (p, v * parents[node][1])
            return parents[node]

        def union(x, y, val):
            root_x, val_x = find(x)
            root_y, val_y = find(y)
            if root_x != root_y:
                parents[root_x] = (root_y, val_y / val_x * val)

        parents = {}
        results = []

        for (a, b), val in zip(equations, values):
            if a not in parents and b not in parents:
                parents[a] = (b, val)
                parents[b] = (b, 1.0)
            elif a not in parents:
                parents[a] = (b, val)
            elif b not in parents:
                parents[b] = (a, 1 / val)
            else:
                union(a, b, val)

        for start, end in queries:
            if start not in parents or end not in parents:
                results.append(-1.0)
                continue

            root_start, val_start = find(start)
            root_end, val_end = find(end)

            if root_start != root_end:
                results.append(-1.0)
            else:
                results.append(val_start / val_end)

        return results
