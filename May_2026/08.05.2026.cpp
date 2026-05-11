/*
LC 3629: Minimum Jumps to Reach End via Prime Teleportation
Topic: Graph
Approach: BFS + Sieve of Eratosthenes
Time: O(n + max(nums) * log(log(max(nums))))
Space: O(n + max(nums))
*/

class Solution {
public:

    vector<bool> isPrime;

    void buildSieve(int maxEle) {

        isPrime.assign(maxEle + 1, true);

        if (maxEle >= 0)
            isPrime[0] = false;

        if (maxEle >= 1)
            isPrime[1] = false;

        for (int num = 2; num * num <= maxEle; num++) {

            if (isPrime[num]) {

                for (int mul = num * num; mul <= maxEle; mul += num) {

                    isPrime[mul] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        int maxEle = 0;

        for (int i = 0; i < n; i++) {

            mp[nums[i]].push_back(i);

            maxEle = max(maxEle, nums[i]);
        }

        buildSieve(maxEle);

        queue<int> que;

        vector<bool> visited(n, false);

        que.push(0);

        visited[0] = true;

        unordered_set<int> seen;

        int steps = 0;

        while (!que.empty()) {

            int size = que.size();

            while (size--) {

                int i = que.front();
                que.pop();

                if (i == n - 1)
                    return steps;

                if (i - 1 >= 0 && !visited[i - 1]) {

                    que.push(i - 1);

                    visited[i - 1] = true;
                }

                if (i + 1 < n && !visited[i + 1]) {

                    que.push(i + 1);

                    visited[i + 1] = true;
                }

                if (isPrime[nums[i]] && !seen.count(nums[i])) {

                    for (int mul = nums[i]; mul <= maxEle; mul += nums[i]) {

                        if (!mp.contains(mul))
                            continue;

                        for (int &j : mp[mul]) {

                            if (!visited[j]) {

                                que.push(j);

                                visited[j] = true;
                            }
                        }
                    }

                    seen.insert(nums[i]);
                }
            }

            steps++;
        }

        return -1;
    }
};
