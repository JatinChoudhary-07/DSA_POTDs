/*
LC 2126: Destroying Asteroids
Topic: Greedy, Sorting
Difficulty: Medium
Approach: Sort asteroids in ascending order. Always consume the smallest possible asteroid first to maximize future mass.
Time: O(n log n)
Space: O(1)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long currMass = mass;

        for (int asteroid : asteroids) {

            if (currMass < asteroid)
                return false;

            currMass += asteroid;
        }

        return true;
    }
};
