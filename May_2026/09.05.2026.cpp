/*
LC 1914: Cyclically Rotating a Grid
Topic: Matrix
Approach: Layer Extraction + Rotation Simulation
Time: O(m * n)
Space: O(m * n)
*/

class Solution {
public:

    void rotate(vector<int>& v, int k) {

        reverse(v.begin(), v.begin() + k);

        reverse(v.begin() + k, v.end());

        reverse(v.begin(), v.end());
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& mat, int k) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ma;

        int str = 0;
        int enr = m - 1;
        int stc = 0;
        int enc = n - 1;

        // Extract layers
        while (str < enr && stc < enc) {

            vector<int> v;

            for (int j = stc; j <= enc; j++) {

                v.push_back(mat[str][j]);
            }

            for (int j = str + 1; j <= enr; j++) {

                v.push_back(mat[j][enc]);
            }

            for (int j = enc - 1; j >= stc; j--) {

                if (str == enr)
                    break;

                v.push_back(mat[enr][j]);
            }

            for (int j = enr - 1; j > str; j--) {

                if (stc == enc)
                    break;

                v.push_back(mat[j][stc]);
            }

            ma.push_back(v);

            str++;
            stc++;
            enc--;
            enr--;
        }

        // Rotate each layer
        for (int i = 0; i < ma.size(); i++) {

            int p = k % ma[i].size();

            rotate(ma[i], p);
        }

        // Reset boundaries
        str = 0;
        enr = m - 1;
        stc = 0;
        enc = n - 1;

        int i = 0;

        // Put rotated layers back
        while (str < enr && stc < enc) {

            int idx = 0;

            for (int j = stc; j <= enc; j++) {

                mat[str][j] = ma[i][idx++];
            }

            for (int j = str + 1; j <= enr; j++) {

                mat[j][enc] = ma[i][idx++];
            }

            for (int j = enc - 1; j >= stc; j--) {

                if (str == enr)
                    break;

                mat[enr][j] = ma[i][idx++];
            }

            for (int j = enr - 1; j > str; j--) {

                if (stc == enc)
                    break;

                mat[j][stc] = ma[i][idx++];
            }

            str++;
            stc++;
            enc--;
            enr--;
            i++;
        }

        return mat;
    }
};
