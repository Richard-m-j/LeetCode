class RecentCounter:
    
    def __init__(self):
        self.requests=deque()

    def ping(self, t: int) -> int:
        lb=t-3000
        self.requests.append(t)
        while self.requests[0] <lb:
            self.requests.popleft()

        return len(self.requests)       


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)