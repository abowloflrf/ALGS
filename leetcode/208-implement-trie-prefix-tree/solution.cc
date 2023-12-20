/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.cn/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (71.95%)
 * Likes:    1566
 * Dislikes: 0
 * Total Accepted:    296.1K
 * Total Submissions: 411.6K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start

// 前缀树的节点定义，节点中没有存字母，children[0] 不为空即 a
class TrieNode {
  public:
    // 到这个节点是否时一个完整单词
    bool isWord;
    // 可能有 26 个字母的子节点
    vector<TrieNode *> children;
    TrieNode() : isWord(false), children(26, nullptr){};
};

class Trie {
  private:
    TrieNode *root;

  public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        // 从树的 root 节点开始往下插入字母
        TrieNode *p = root;
        for (auto c : word) {
            // 若已经有则不插入
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }

    bool search(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            if (p->children[c - 'a'] == nullptr) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        if (!p)
            return false;
        if (p->isWord)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto c : prefix) {
            if (p->children[c - 'a'] == nullptr) {
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
