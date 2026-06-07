/*
LC 3121: Count the Number of Special Characters II
Topic: Strings
Difficulty: Medium
Approach: Store last occurrence of lowercase and first occurrence of uppercase. A character is special if last lowercase appears before first uppercase.
Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        for (int i = 0; i < word.size(); i++) {

            char c = word[i];

            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = i;
            }
            else {
                if (upper[c - 'A'] == -1) {
                    upper[c - 'A'] = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] != -1 &&
                upper[i] != -1 &&
                lower[i] < upper[i]) {
                ans++;
            }
        }

        return ans;
    }
};
