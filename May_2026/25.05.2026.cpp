/*
LC 1871: Jump Game VII
Topic: Greedy
Difficulty: Medium
Approach: Prefix Sum Reachability
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        if (s[n - 1] == '1')
            return false;

        vector<int> diff(n + 1, 0);

        int active = 0;

        for (int i = 0; i < n; i++) {

            active += diff[i];

            if (i == 0 || (active > 0 && s[i] == '0')) {

                int l = min(i + minJump, n);
                int r = min(i + maxJump + 1, n);

                diff[l]++;
                diff[r]--;
            }
        }

        return active > 0;
    }
};
