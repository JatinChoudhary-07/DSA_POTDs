/*
LC 153: Find Minimum in Rotated Sorted Array
Topic: Binary Search
Approach: Binary Search
Time: O(log n)
Space: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r) {

            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[n - 1])
                l = mid + 1;
            else
                r = mid;
        }

        return nums[l];
    }
};
