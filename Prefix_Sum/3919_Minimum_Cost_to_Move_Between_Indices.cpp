// LC 3919: Minimum Cost to Move Between Indices
// Topic: Prefix Sum
// Difficulty: Medium
// Approach: Closest Index + Prefix Sum
// Time: O(n + q)
// Space: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();

        // closest array build up
        vector<int> closest(n);

        for (int i = 0; i < n; i++) {
            if (i == 0)
                closest[i] = 1;

            else if (i == n - 1)
                closest[i] = n - 2;

            else {
                int lD = nums[i] - nums[i - 1];
                int rD = nums[i + 1] - nums[i];

                closest[i] = (lD <= rD) ? i - 1 : i + 1;
            }
        }

        // calculating prefix sums
        vector<long long> forward(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            int cost = (closest[i] == i + 1) ? 1 : diff;

            forward[i + 1] = forward[i] + cost;
        }

        vector<long long> backward(n, 0);

        for (int i = n - 1; i > 0; i--) {
            int diff = nums[i] - nums[i - 1];
            int cost = (closest[i] == i - 1) ? 1 : diff;

            backward[i - 1] = backward[i] + cost;
        }

        // solving queries
        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            if (l <= r) {
                ans.push_back((int)(forward[r] - forward[l]));
            }
            else {
                ans.push_back((int)(backward[r] - backward[l]));
            }
        }

        return ans;
    }
};
