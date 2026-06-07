/*
LC 1674: Minimum Moves to Make Array Complementary
Topic: Prefix Sum
Approach: Difference Array
Time: O(n + limit)
Space: O(limit)
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {

            int a = min(nums[i], nums[n - 1 - i]);
            int b = max(nums[i], nums[n - 1 - i]);

            int sum = a + b;

            // Initially 2 moves everywhere
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;

            // 1 move range
            diff[a + 1] -= 1;
            diff[b + limit + 1] += 1;

            // 0 move at exact sum
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;

        int curr = 0;

        for (int s = 2; s <= 2 * limit; s++) {

            curr += diff[s];

            ans = min(ans, curr);
        }

        return ans;
    }
};
