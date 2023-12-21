/*
 * @lc app=leetcode.cn id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.cn/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (60.15%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    19.6K
 * Total Submissions: 32.5K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\n"mouse"'
 *
 * You are given an array of strings products and a string searchWord.
 *
 * Design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with searchWord. If there are more than three products with a
 * common prefix return the three lexicographically minimums products.
 *
 * Return a list of lists of the suggested products after each character of
 * searchWord is typed.
 *
 *
 * Example 1:
 *
 *
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output:
 * [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"].
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"].
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
 *
 *
 * Example 2:
 *
 *
 * Input: products = ["havana"], searchWord = "havana"
 * Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * Explanation: The only word "havana" will be always suggested while typing
 * the search word.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= products.length <= 1000
 * 1 <= products[i].length <= 3000
 * 1 <= sum(products[i].length) <= 2 * 10^4
 * All the strings of products are unique.
 * products[i] consists of lowercase English letters.
 * 1 <= searchWord.length <= 1000
 * searchWord consists of lowercase English letters.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start

class TrieTreeNode {
  public:
    vector<TrieTreeNode *> children;
    bool isWord;

    vector<string> ans;
    string tmp;

    TrieTreeNode() {
        this->children = vector<TrieTreeNode *>(26, nullptr);
        this->isWord = false;
    }
    ~TrieTreeNode();

    void add(string word) {
        TrieTreeNode *p = this;
        for (char c : word) {
            if (p->children[c - 'a'] == nullptr) {
                p->children[c - 'a'] = new TrieTreeNode();
            }
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }
    void find(TrieTreeNode *node) {
        // 找到该位置字典序前3个单词
        if (node == nullptr || ans.size() >= 3) {
            return;
        }
        if (node->isWord) {
            ans.push_back(tmp);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                tmp += (i + 'a');
                find(node->children[i]);
                tmp.pop_back();
            }
        }
    }
};

class Solution {
  public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        TrieTreeNode *root = new TrieTreeNode();
        for (auto const &p : products) {
            root->add(p);
        }
        vector<vector<string>> ans(searchWord.size());
        TrieTreeNode *pivot = root;

        string prefix;
        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];
            prefix += c;
            if (!pivot) {
                break;
            }
            pivot = pivot->children[c - 'a'];
            root->find(pivot);
            for (auto s : root->ans) {
                ans[i].push_back(prefix + s);
            }
            root->tmp = "";
            root->ans = {};
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution s;
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";
    s.suggestedProducts(products, searchWord);
    return 0;
}
