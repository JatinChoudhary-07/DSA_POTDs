/*
LC 3093: Longest Common Suffix Queries
Topic: Trie
Difficulty: Hard
Approach: Build a reverse Trie on wordsContainer. Each node stores the index of the shortest word passing through it. Query by traversing the suffix characters in reverse.
Time: O(total characters in wordsContainer + total characters in wordsQuery)
Space: O(total characters in wordsContainer)
*/

class Solution {
public:
    struct TrieNode {
        int idx;
        TrieNode* child[26];

        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                if (child[i] != nullptr) {
                    delete child[i];
                    child[i] = nullptr;
                }
            }
        }
    };

    TrieNode* getNode(int i) {
        TrieNode* newNode = new TrieNode();
        newNode->idx = i;

        for (int k = 0; k < 26; k++) {
            newNode->child[k] = nullptr;
        }

        return newNode;
    }

    void insert(TrieNode* root, vector<string>& words, int id) {
        int n = words[id].size();

        TrieNode* crawl = root;

        for (int i = n - 1; i >= 0; i--) {
            int index = words[id][i] - 'a';

            if (crawl->child[index] == nullptr) {
                crawl->child[index] = getNode(id);
            }

            crawl = crawl->child[index];

            if (words[crawl->idx].size() > n) {
                crawl->idx = id;
            }
        }
    }

    int search(string& s, TrieNode* root) {
        int res = root->idx;

        TrieNode* crawl = root;
        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            int idx = s[i] - 'a';

            crawl = crawl->child[idx];

            if (crawl == nullptr) {
                return res;
            }

            res = crawl->idx;
        }

        return res;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        TrieNode* root = getNode(0);

        for (int i = 0; i < wordsContainer.size(); i++) {

            if (wordsContainer[i].size() <
                wordsContainer[root->idx].size()) {
                root->idx = i;
            }

            insert(root, wordsContainer, i);
        }

        vector<int> ans;

        for (auto& query : wordsQuery) {
            ans.push_back(search(query, root));
        }

        delete root;

        return ans;
    }
};
