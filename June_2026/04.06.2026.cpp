/*
LC 3751: Total Waviness of Numbers in Range I
Topic: Brute Force, String
Difficulty: Medium
Approach: Convert each number to a string and count peaks and valleys by checking every middle digit against its adjacent digits.
Time: O((num2 - num1 + 1) * d)
Space: O(d)
*/

class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int ans = 0;

        for (int num = num1; num <= num2; num++) {

            string s = to_string(num);

            for (int i = 1; i < (int)s.size() - 1; i++) {

                if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                    (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
