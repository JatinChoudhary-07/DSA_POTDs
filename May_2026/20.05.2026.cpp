/*
LC 2657: Find the Prefix Common Array of Two Arrays
Topic: Arrays
Approach: Frequency Counting
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n = A.size();

        vector<int> freq(n + 1, 0);

        vector<int> ans(n);

        int common = 0;

        for (int i = 0; i < n; i++) {

            freq[A[i]]++;

            if (freq[A[i]] == 2)
                common++;

            freq[B[i]]++;

            if (freq[B[i]] == 2)
                common++;

            ans[i] = common;
        }

        return ans;
    }
};
