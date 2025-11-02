#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

using vi = vector<int>;
using vii = vector<pair<int, int>>;
#define all(x) begin(x), end(x)
#define contains(c, x) (c).find(x) != (c).end()

class Solution
{
public:
    // Time: O(nlogn) | Space: O(n)
    vi solve1(vi &nums, int t)
    {
        vii tmp;
        int n = nums.size();
        tmp.reserve(n);
        for (int i = 0; i < n; ++i)
            tmp.emplace_back(nums[i], i);
        sort(all(tmp));
        for (int i = 0, j = n - 1; i < j;)
        {
            const auto &[a, a_i] = tmp[i];
            const auto &[b, b_j] = tmp[j];
            if (a + b == t)
                return {a_i, b_j};
            else if (a + b < t)
                ++i;
            else
                --j;
        }
        return {};
    }

    // Time: O(n) | Space: O(n)
    vi solve2(vi &nums, int t)
    {
        unordered_map<int, int> seen;
        int n = nums.size();
        seen.reserve(n);

        for (int i = 0; i < n; ++i)
        {
            if (contains(seen, t - nums[i]))
                return {i, seen[t - nums[i]]};
            seen[nums[i]] = i;
        }
        return {};
    }

    vi twoSum(vi &nums, int target)
    {
        // return solve1(nums, target);
        return solve2(nums, target);
    }
};