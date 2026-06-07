/*
LC 2770: Maximum Number of Jumps to Reach the Last Index
Topic: DP
Approach: Recursion + Memoization
Time: O(n^2)
Space: O(n)
*/

class Solution {
public:

    int n, target;

    vector<int> dp;

    int solve(int i, vector<int>& nums) {

        if (i == n - 1)
            return 0;

        if (dp[i] != -2)
            return dp[i];

        int ans = -1;

        for (int j = i + 1; j < n; j++) {

            if (abs(nums[j] - nums[i]) <= target) {

                int next = solve(j, nums);

                if (next != -1) {

                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int t) {

        n = nums.size();

        target = t;

        dp.assign(n, -2);

        return solve(0, nums);
    }
};
