class Solution:
    # Time: O(nlogn) | Space: O(1)
    def solve1(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s, t = sorted(s), sorted(t)
        return s == t
    
    # Time: O(n) | Space: O(n)
    def solve2(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        from collections import Counter
        c1, c2 = Counter(s), Counter(t)
        return c1 == c2

    def isAnagram(self, s: str, t: str) -> bool:
        # return self.solve1(s, t)
        return self.solve2(s, t)