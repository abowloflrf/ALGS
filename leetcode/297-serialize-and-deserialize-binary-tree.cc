/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (43.21%)
 * Likes:    2495
 * Dislikes: 122
 * Total Accepted:    276.4K
 * Total Submissions: 609.7K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Example: 
 *
 *
 * You may serialize the following tree:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 *
 * as "[1,2,3,null,null,4,5]"
 *
 *
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 *
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 *
 */

#include "utils/tree.h"
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "[]";
        queue<TreeNode *> q;
        string res = "[";
        q.push(root);
        while (true) {
            int size = q.size();
            string currentLevel;
            int emptyNode = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node == nullptr) {
                    currentLevel += "null,";
                    emptyNode++;
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    currentLevel += (to_string(node->val) + ",");
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (size == emptyNode) {
                break;
            } else {
                res += currentLevel;
            }
        }
        res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        // string to vector
        data.erase(data.size() - 1);
        data.erase(0, 1);
        queue<TreeNode *> q;
        istringstream in(data);
        string token;
        while (std::getline(in, token, ',')) {
            if (token == "null")
                q.push(nullptr);
            else
                q.push(new TreeNode(stoi(token)));
        }
        int s  =q.size();
        return helper(q);
    }

  private:
    TreeNode *helper(queue<TreeNode *> &q) {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr)
            return nullptr;
        node->left = helper(q);
        node->right = helper(q);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

int main() {
    Codec c;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string s = c.serialize(root);

    //
    TreeNode *r = c.deserialize("[1,2,3,null,null,4,5]");
    int a;
    return 0;
}

// 超时。。。。
// TreeNode *deserialize(string data) {
//     // string to vector
//     data.erase(data.size() - 1);
//     data.erase(0, 1);
//     vector<TreeNode *> arr;
//     istringstream in(data);
//     string token;
//     while (std::getline(in, token, ',')) {
//         if (token == "null")
//             arr.push_back(nullptr);
//         else
//             arr.push_back(new TreeNode(stoi(token)));
//     }
//     if (arr.empty())
//         return nullptr;
//     // 计算二叉树的深度
//     int leveln = 0;
//     int tmp = arr.size() + 1;
//     while (tmp != 1) {
//         leveln++;
//         tmp >>= 1;
//     }
//     // 使用辅助的队列组装二叉树
//     TreeNode *root = arr[0];
//     queue<pair<TreeNode *, int>> q;
//     q.push(make_pair(root, 0));
//     for (int currentLevel = 1; currentLevel < leveln; currentLevel++) {
//         int levelSize = q.size();
//         for (int i = 0; i < levelSize; i++) {
//             auto nodePair = q.front();
//             q.pop();

//             int leftIndex = nodePair.second * 2 + 1;
//             int rightIndex = leftIndex + 1;
//             if (arr[leftIndex] != nullptr) {
//                 q.push(make_pair(arr[leftIndex], leftIndex));
//                 nodePair.first->left = arr[leftIndex];
//             }
//             if (arr[rightIndex] != nullptr) {
//                 q.push(make_pair(arr[rightIndex], rightIndex));
//                 nodePair.first->right = arr[rightIndex];
//             }
//         }
//     }
//     return root;
// }