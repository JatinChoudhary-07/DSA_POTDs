/*
LC 3633: Earliest Finish Time for Land and Water Rides I
Topic: Brute Force, Simulation
Difficulty: Easy
Approach: Try every Land-Water and Water-Land combination. Compute finish time for both orders and keep the minimum.
Time: O(n * m)
Space: O(1)
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Land -> Water
                int landFinish = landStartTime[i] + landDuration[i];
                int finish1 = max(landFinish, waterStartTime[j]) +
                              waterDuration[j];

                res = min(res, finish1);

                // Water -> Land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int finish2 = max(waterFinish, landStartTime[i]) +
                              landDuration[i];

                res = min(res, finish2);
            }
        }

        return res;
    }
};
