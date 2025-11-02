#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define contains(c, x) (c).find(x) != (c).end()
using vi = vector<int>;

class Solution
{
public:
    // Time: O(n) | Space: O(n)
    bool solve1(vi &nums)
    {
        unordered_set<int> seen;
        seen.reserve(nums.size());
        for (const auto &x : nums)
        {
            if (contains(seen, x))
                return true;
            seen.insert(x);
        }
        return false;
    }

    // Time: O(nlogn) | Space: O(1)
    bool solve2(vi &nums)
    {
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 1 < nums.size(); ++i)
            if (nums[i] == nums[i+1])
                return true;
        return false;
    }

    bool containsDuplicate(vi &nums)
    {
        // return solve1(nums);
        return solve2(nums);
    }
};