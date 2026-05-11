/*
LC 2553: Separate the Digits in an Array
Topic: Arrays
Approach: Digit Extraction
Time: O(n * log10(max(nums[i])))
Space: O(n)
*/

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        list<int> number;

        for (int n : nums) {

            number.clear();

            while (n > 0) {

                int digit = n % 10;

                n = n / 10;

                number.push_front(digit);
            }

            ans.insert(ans.end(), number.begin(), number.end());
        }

        return ans;
    }
};
