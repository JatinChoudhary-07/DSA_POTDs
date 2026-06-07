/*
LC 796: Rotate String
Topic: Strings
Approach: String Concatenation
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length())
            return false;

        s = s + s;

        if (s.find(goal) < s.size())
            return true;

        return false;
    }
};
