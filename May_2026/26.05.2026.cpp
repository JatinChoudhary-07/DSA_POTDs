/*
LC 3120: Count the Number of Special Characters I
Topic: Strings
Difficulty: Easy
Approach: Hash Set
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {

        int ans = 0;

        unordered_set<char> st(word.begin(), word.end());

        for (char c = 'A'; c <= 'Z'; c++) {
            if (st.count(c) && st.count(c + 32))
                ans++;
        }

        return ans;
    }
};
