/*
LC 1306: Jump Game III
Topic: Graph
Approach: DFS
Time: O(n)
Space: O(n)
*/

class Solution {
public:

    bool dfs(vector<int>& arr, int i) {

        int n = arr.size();

        if (i < 0 || i >= n || arr[i] < 0)
            return false;

        if (arr[i] == 0)
            return true;

        arr[i] *= -1;

        bool left = dfs(arr, i - arr[i]);

        bool right = dfs(arr, i + arr[i]);

        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {

        return dfs(arr, start);
    }
};
