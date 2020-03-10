/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (41.45%)
 * Likes:    2400
 * Dislikes: 43
 * Total Accepted:    244.9K
 * Total Submissions: 555.9K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Example:
 *
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");
 * trie.search("app");     // returns true
 *
 *
 * Note:
 *
 *
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 *
 *
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start

// 前缀树节点
class TrieNode {
  public:
    TrieNode() : isWord(false), children(26, nullptr){};
    ~TrieNode() {
        for (auto c : children)
            if (c)
                delete c;
    };
    bool isWord;
    vector<TrieNode *> children;
};

class Trie {
  public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *a = find(word);
        if (a == nullptr)
            return false;
        if (a->isWord)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) { return find(prefix) != nullptr; }

  private:
    TrieNode *root;
    // 在前缀树中寻找是否有以prefix开头的字符串，有则返回其末尾节点，无则返回空指针
    TrieNode *find(string prefix) {
        TrieNode *p = root;
        for (auto c : prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr)
                return nullptr;
        }
        return p;
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
