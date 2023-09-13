class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        n = len(isConnected)
        notVisited = [True]*n

        def helperDFS(node: int):
            notVisited[node] = False
            for i in range(n):
                if notVisited[i] and isConnected[node][i]:
                    helperDFS(i)
            
        ans = 0
        for i in range(n):
            if notVisited[i]:
                ans += 1
                helperDFS(i)
        return ans
        

