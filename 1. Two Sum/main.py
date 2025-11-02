class Solution:
    # Time: O(nlogn) | Space: O(n)
    def solve1(self, nums: List[int], t: int) -> List[int]:
        tmp = []
        for i, x in enumerate(nums):
            tmp.append((x, i))
        tmp.sort()
        i, j = 0, len(nums)-1
        while i < j:
            a, a_i = tmp[i]
            b, b_j = tmp[j]
            if a + b == t:
                return [a_i, b_j]
            elif a + b < t:
                i += 1
            else:
                j -= 1
        return []
    
    # Time: O(n) | Space: O(n)
    def solve2(self, nums: List[int], t: int) -> List[int]:
        tmp = dict()
        for i, x in enumerate(nums):
            if (j:=tmp.get(t-x)) is not None:
                return [i, j]
            tmp[x] = i
        return []


    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return self.solve1(nums, target)
        # return self.solve2(nums, target)
