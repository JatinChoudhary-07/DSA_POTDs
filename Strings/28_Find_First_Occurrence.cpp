// LC 28: Find the Index of the First Occurrence in a String
// Topic: Strings
// Approach: Brute Force (Using Substring)
// Time: O(n * m)
// Space: O(m)

#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();

        if (n == 0) return 0;
        if (h < n) return -1;

        char firstChar = needle[0];

        for (int i = 0; i <= h - n; i++)
            if (haystack[i] == firstChar && haystack.substr(i, n) == needle)
                return i;

        return -1;
    }
};
