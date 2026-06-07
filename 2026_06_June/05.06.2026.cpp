/*
LC 3753: Total Waviness of Numbers in Range II
Topic: Digit DP, Math
Difficulty: Hard
Approach: Precompute all 3-digit waviness patterns. For each pattern, count how many times it appears as a contiguous 3-digit block in numbers from 0 to N using digit counting, then use range query: f(B) - f(A-1).
Time: O(570 * log10(N))
Space: O(570)
*/

using ll = long long;

class Solution {
    static inline int waves[570];

    static inline bool init = []() {
        int j = 0;

        for (int i = 0; i < 1000; i++) {
            int r = i % 10;
            int m = (i / 10) % 10;
            int l = (i / 100) % 10;

            if ((m > max(l, r)) || (m < min(l, r))) {
                waves[j++] = i;
            }
        }

        return 0;
    }();

public:
    long long totalWaviness(long long A, long long B) {
        return waveCount(B) - waveCount(A - 1);
    }

private:
    long long waveCount(long long num) {
        if (num < 100) return 0;

        return accumulate(begin(waves), end(waves), 0LL,
                          [&](long long a, int p) {
                              return a + countWays(num, p);
                          });
    }

    long long countWays(long long num, int pattern) {

        long long t = pattern < 100;
        long long count = 0;
        long long mult = 1;

        for (int i = 0; mult * 100 <= num; i++) {

            long long pre = num / (mult * 1000);
            long long cur = (num / mult) % 1000;
            long long suf = num % mult;

            long long ways = 0;

            if (cur > pattern) {
                ways = pre - t + 1;
            }
            else if (cur == pattern) {
                ways = max(0LL, pre - t);
                count += suf + 1;
            }
            else {
                ways = max(0LL, pre - t);
            }

            count += ways * mult;
            mult *= 10;
        }

        return count;
    }
};
