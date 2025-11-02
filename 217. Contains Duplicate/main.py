class Solution:
    # Time: O(n) | Space: O(n)
    def solve1(self, nums: List[int]) -> bool:
        seen = set()
        for x in nums:
            if x in seen:
                return True
            seen.add(x)
        return False
    
    # Time: O(nlogn) | Space: O(1)
    def solve2(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False

    def containsDuplicate(self, nums: List[int]) -> bool:
        # return self.solve1(nums)
        return self.solve2(nums)