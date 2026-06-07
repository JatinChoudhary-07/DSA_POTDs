/*
LC 154: Find Minimum in Rotated Sorted Array II
Topic: Binary Search
Approach: Binary Search
Time: O(log n) Average, O(n) Worst Case
Space: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r) {

            int mid = l + (r - l) / 2;

            if (nums[mid] == nums[r]) {

                r--;

                continue;
            }

            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        return nums[l];
    }
};
