class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        visited = [False]*n

        listProvinces = []
        def helperDFS(node: int):
            connection = {node}
            visited[node] = True
            for i in range(n):
                if isConnected[node][i] and not visited[i]:
                    connection.update(helperDFS(i))
            return connection

        for i in range(n):
            if not visited[i]:
                listProvinces.append(helperDFS(i))
        return len(listProvinces)
        

