# Last updated: 7/24/2025, 8:28:38 AM
class RecentCounter:
    
    def __init__(self):
        self.requests=deque()

    def ping(self, t: int) -> int:
        
        self.requests.append(t)
        while self.requests[0] <t-3000:
            self.requests.popleft()

        return len(self.requests)       


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)