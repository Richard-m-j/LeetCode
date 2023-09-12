class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False]*n

        def helperDFS(node: int):
            visited[node] = True
            for i in range(n):
                if isConnected[node][i] and not visited[i]:
                    helperDFS(i)
            
        ans = 0
        for i in range(n):
            if not visited[i]:
                ans += 1
                helperDFS(i)
        return ans
        

