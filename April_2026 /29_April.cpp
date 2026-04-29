
// LC 3225: Maximum Score From Grid Operations
// Topic: DP (Memoization) + Prefix Sum
// Difficulty: Hard
// Approach: Column-wise DP with state (prevTaken, prevHeight, col)
// Time: O(n^3)
// Space: O(n^3)

#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    using ll = long long;

    int n;
    ll dp[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col,
             vector<vector<int>>& grid,
             vector<vector<ll>>& colPrefSum) {

        if (col == n) return 0;

        if (dp[prevTaken][prevHeight][col] != -1)
            return dp[prevTaken][prevHeight][col];

        ll result = 0;

        for (int h = 0; h <= n; h++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if (!prevTaken && col - 1 >= 0 && h > prevHeight)
                prevColScore += colPrefSum[h][col] - colPrefSum[prevHeight][col];

            if (prevHeight > h)
                currColScore += colPrefSum[prevHeight][col + 1] - colPrefSum[h][col + 1];

            ll take = currColScore + prevColScore +
                      solve(true, h, col + 1, grid, colPrefSum);

            ll notTake = prevColScore +
                         solve(false, h, col + 1, grid, colPrefSum);

            result = max({result, take, notTake});
        }

        return dp[prevTaken][prevHeight][col] = result;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();

        memset(dp, -1, sizeof(dp));

        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for (int col = 1; col <= n; col++)
            for (int row = 1; row <= n; row++)
                colPrefSum[row][col] =
                    colPrefSum[row - 1][col] + grid[row - 1][col - 1];

        return solve(false, 0, 0, grid, colPrefSum);
    }
};
