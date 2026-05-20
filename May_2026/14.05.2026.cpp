/*
LC 2784: Check if Array is Good
Topic: Arrays
Approach: Sorting
Time: O(n log n)
Space: O(1)
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        if (n == 1)
            return false;

        if (n == 2) {

            if (nums[0] == 1 && nums[1] == 1)
                return true;

            return false;
        }

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] != i + 1)
                return false;
        }

        return nums[n - 1] == nums[n - 2];
    }
};
