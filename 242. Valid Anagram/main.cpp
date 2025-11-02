#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define all(x) begin(x), end(x)

class Solution
{
public:
    // Time: O(nlogn) | Space: O(1)
    bool solve1(string &s, string &t)
    {
        if (s.length() != t.length())
            return false;
        sort(all(s));
        sort(all(t));
        return s == t;
    }

    // Time: O(n) | Space: O(n)
    bool solve2(const string &s, const string &t)
    {
        if (s.length() != t.length())
            return false;
        unordered_map<char, size_t> cnt;
        cnt.reserve(s.length());
        for(const auto& c : s)
            cnt[c]++;
        for(const auto& c : t)
            if (--cnt[c] == 0)
                cnt.erase(c);
        return !cnt.size();
    }

    bool isAnagram(string &s, string &t)
    {
        return solve1(s, t);
        // return solve2(s, t);
    }
};