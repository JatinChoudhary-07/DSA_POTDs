/*
LC 1861: Rotating the Box
Topic: Matrix
Approach: Rotate Matrix + Gravity Simulation
Time: O(m * n)
Space: O(m * n)
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> result(n, vector<char>(m));

        // Rotating the box
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                result[i][j] = boxGrid[j][i];
            }
        }

        for (vector<char>& row : result) {

            reverse(row.begin(), row.end());
        }

        // Apply gravity
        for (int j = 0; j < m; j++) {

            int bottomSpaceRow = n - 1;

            for (int i = n - 1; i >= 0; i--) {

                if (result[i][j] == '*') {

                    bottomSpaceRow = i - 1;

                    continue;
                }

                if (result[i][j] == '#') {

                    result[i][j] = '.';

                    result[bottomSpaceRow--][j] = '#';
                }
            }
        }

        return result;
    }
};
