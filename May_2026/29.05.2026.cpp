/*
LC 3300: Minimum Element After Replacement With Digit Sum
Topic: Math
Difficulty: Easy
Approach: Replace each number with the sum of its digits and track the minimum.
Time: O(n * digits)
Space: O(1)
*/

class Solution {
public:
    int minElement(vector<int>& nums) {

        int mini = INT_MAX;

        for (int x : nums) {

            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            mini = min(mini, sum);
        }

        return mini;
    }
};
