/*
LC 2144: Minimum Cost of Buying Candies With Discount
Topic: Greedy, Sorting
Difficulty: Easy
Approach: Sort candies in descending order. For every group of three candies, pay for the two most expensive and take the third for free.
Time: O(n log n)
Space: O(1)
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 == 0) continue;
            ans += cost[i];
        }

        return ans;
    }
};
